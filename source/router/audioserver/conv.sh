#!/bin/sh

# Convert audio files to desired format
SOURCE_DIR="/path/to/source"
DEST_DIR="/path/to/destination"
LOG_FILE="/var/log/audio_conversion.log"

convert_audio() {
    local src_file="$1"
    local dest_file="$2"
    ffmpeg -i "$src_file" -acodec mp3 "$dest_file"
}

log_message() {
    local message="$1"
    echo "$(date +'%Y-%m-%d %H:%M:%S') - $message" >> "$LOG_FILE"
}

mkdir -p "$DEST_DIR"

for src_file in "$SOURCE_DIR"/*; do
    base_name=$(basename "$src_file")
    dest_file="$DEST_DIR/${base_name%.*}.mp3"
    log_message "Converting $src_file to $dest_file"
    convert_audio "$src_file" "$dest_file"
    log_message "Finished converting $src_file"
done

log_message "All conversions completed."
