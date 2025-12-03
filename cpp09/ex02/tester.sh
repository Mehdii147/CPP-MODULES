#!/bin/bash

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

PROGRAM="./PmergeMe"

# 1. Check if executable exists
if [ ! -f "$PROGRAM" ]; then
    echo -e "${RED}Error: $PROGRAM not found.${NC}"
    echo "Please compile your project first (run 'make')."
    exit 1
fi

# Function to verify sorting
run_test() {
    local TEST_NAME="$1"
    local INPUT="$2"
    
    echo -e "${CYAN}Running: $TEST_NAME${NC}"

    # Generate Expected Output using system sort
    # We replace spaces with newlines, sort numerically, then join back with spaces
    EXPECTED=$(echo "$INPUT" | tr ' ' '\n' | sort -n | tr '\n' ' ' | sed 's/ $//')

    # Run User Program
    # We capture stdout, look for "After:", remove the prefix, and normalize spaces
    OUTPUT=$($PROGRAM $INPUT 2>&1)
    
    # Check for crashes
    if [ $? -ne 0 ]; then
        echo -e "${RED}[FAIL]${NC} Program crashed or returned error code."
        return
    fi

    # Extract the sorted sequence from the output
    ACTUAL=$(echo "$OUTPUT" | grep "After:" | sed 's/After:[[:space:]]*//' | tr ' ' '\n' | tr '\n' ' ' | sed 's/ $//')

    # Compare
    if [ "$ACTUAL" == "$EXPECTED" ]; then
        echo -e "${GREEN}[OK]${NC} Output is sorted correctly."
    else
        echo -e "${RED}[FAIL]${NC} Sorting incorrect."
        echo "Expected first 5: $(echo $EXPECTED | awk '{print $1, $2, $3, $4, $5}') ..."
        echo "Got first 5:      $(echo $ACTUAL | awk '{print $1, $2, $3, $4, $5}') ..."
    fi
    echo "---------------------------------------------------"
}

# 2. Generator Logic (Linux jot vs Mac jot)
generate_numbers() {
    local COUNT=$1
    local MAX=$2
    if command -v jot > /dev/null; then
        jot -i 1-$MAX -n $COUNT | tr '\n' ' '
    elif command -v jot > /dev/null; then
        jot -r $COUNT 1 $MAX | tr '\n' ' '
    else
        echo ""
    fi
}

# --- TESTS ---

# Test 1: Simple manual case
run_test "Simple Small List" "5 3 9 7 4"

# Test 2: Already sorted
run_test "Already Sorted" "1 2 3 4 5"

# Test 3: Reverse sorted
run_test "Reverse Sorted" "9 8 7 6 5 4 3 2 1"

# Test 4: 100 Random Numbers
NUMS_100=$(generate_numbers 100 1000)
if [ -z "$NUMS_100" ]; then
    echo "Skipping random tests (jot/jot not found)"
else
    run_test "100 Random Numbers" "$NUMS_100"
fi

# Test 5: 3000 Random Numbers (Subject Requirement)
NUMS_3000=$(generate_numbers 3000 100000)
if [ -n "$NUMS_3000" ]; then
    echo -e "${CYAN}Running: 3000 Random Numbers (Performance Check)${NC}"
    # We run this one slightly differently to show the time output
    $PROGRAM $NUMS_3000 > temp_output.txt
    
    # Check correctness silently first
    ACTUAL_LAST=$(grep "After:" temp_output.txt | sed 's/After:[[:space:]]*//' | tr ' ' '\n' | tr '\n' ' ' | sed 's/ $//')
    EXPECTED_LAST=$(echo "$NUMS_3000" | tr ' ' '\n' | sort -n | tr '\n' ' ' | sed 's/ $//')
    
    if [ "$ACTUAL_LAST" == "$EXPECTED_LAST" ]; then
        echo -e "${GREEN}[OK]${NC} 3000 elements sorted correctly."
        # Show the timing lines
        grep "Time to process" temp_output.txt
    else
        echo -e "${RED}[FAIL]${NC} 3000 elements sorting failed."
    fi
    rm temp_output.txt
    echo "---------------------------------------------------"
fi

# Test 6: Error Handling
echo -e "${CYAN}Running: Error Cases${NC}"
ERR1=$($PROGRAM -1 5 2 2>&1)
if echo "$ERR1" | grep -q "Error"; then
    echo -e "${GREEN}[OK]${NC} Negative number detected."
else
    echo -e "${RED}[FAIL]${NC} Negative number NOT detected."
fi

ERR2=$($PROGRAM 5 a 2 2>&1)
if echo "$ERR2" | grep -q "Error"; then
    echo -e "${GREEN}[OK]${NC} Non-numeric input detected."
else
    echo -e "${RED}[FAIL]${NC} Non-numeric input NOT detected."
fi