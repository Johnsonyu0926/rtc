#!/bin/sh

if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <URL> <Output File>"
    exit 1
fi

URL="$1"
OUTPUT_FILE="$2"
curl -A "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.110 Safari/537.36" "$URL" -L -o "$OUTPUT_FILE"
