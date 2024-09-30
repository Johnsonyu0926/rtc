#!/bin/sh

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <volume-level>"
    exit 1
fi

VOLUME_LEVEL="$1"

if ! [[ "$VOLUME_LEVEL" =~ ^[0-9]+$ ]]; then
    echo "Error: Volume level must be a number."
    exit 1
fi

if [ "$VOLUME_LEVEL" -lt 0 ] || [ "$VOLUME_LEVEL" -gt 100 ]; then
    echo "Error: Volume level must be between 0 and 100."
    exit 1
fi

amixer set Master "${VOLUME_LEVEL}%"
