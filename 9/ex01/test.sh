#!/bin/bash

VERBOSE=false
if [ "$1" == "--verbose" ]; then
    VERBOSE=true
fi

INPUTS=(
    "8 9 * 9 - 9 - 9 - 4 - 1 +"
    "7 7 * 7 -"
    "1 2 * 2 / 2 * 2 4 - +"
    "8"
    "    8   9  * 9 - 9 - 9 -   4 - 1 + "
    "1 2 3 4 5 + + + +"
    "      "
    ""
    "-1"
    "0 0 + 1"
    "0 0 + +"
    "1 +"
    "1 0 /"
)

EXPECTS=(
    42
    42
    0
    8
    42
    15
    "ERROR"
    "ERROR"
    "ERROR"
    "ERROR"
    "ERROR"
    "ERROR"
    "ERROR"
)

function print_verbose() {
    if $VERBOSE; then printf "%s\n" "$1"; fi
}

function test_failed() {
    echo expect $1, but got $2
    echo "KO"
    exit 1
}

# Disable wildcard expansion
set -f
# Build
make

for i in ${!INPUTS[@]}
do
    input=${INPUTS[i]}
    expected=${EXPECTS[i]}
    actual=`./RPN "$input"`
    status=$?

    print_verbose "input: \"$input\""
    print_verbose "expected: $expected, actual: $actual, exit status: $status"
    if [ $expected == "ERROR" ] && [ $status -eq 0 ]; then
        test_failed "non-zero status" $status
    elif [ $expected != "ERROR" ] && [ "$actual" != "$expected" ]; then
        test_failed "$expected" "$actual"
    fi
    print_verbose "OK"
done

echo "ALL OK"
