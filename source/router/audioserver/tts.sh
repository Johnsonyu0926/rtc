#!/bin/sh

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <text>"
    exit 1
fi

TEXT="$1"
TTS_COMMAND="tts --text \"$TEXT\" --out_path /tmp/tts_output.wav"

eval $TTS_COMMAND

if [ $? -eq 0 ]; then
    ffplay -autoexit /tmp/tts_output.wav
else
    echo "Failed to generate TTS audio."
    exit 1
fi

rm -f /tmp/tts_output.wav
