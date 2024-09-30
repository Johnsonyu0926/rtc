#!/bin/sh

AUDIO_SERVER_PID_FILE="/var/run/audioserver.pid"

start_audioserver() {
    if [ -f $AUDIO_SERVER_PID_FILE ]; then
        echo "Audioserver is already running."
    else
        echo "Starting audioserver..."
        /usr/bin/audioserver &
        echo $! > $AUDIO_SERVER_PID_FILE
        echo "Audioserver started."
    fi
}

stop_audioserver() {
    if [ -f $AUDIO_SERVER_PID_FILE ]; then
        PID=$(cat $AUDIO_SERVER_PID_FILE)
        echo "Stopping audioserver..."
        kill $PID
        rm -f $AUDIO_SERVER_PID_FILE
        echo "Audioserver stopped."
    else
        echo "Audioserver is not running."
    fi
}

restart_audioserver() {
    stop_audioserver
    start_audioserver
}

case "$1" in
    start)
        start_audioserver
        ;;
    stop)
        stop_audioserver
        ;;
    restart)
        restart_audioserver
        ;;
    *)
        echo "Usage: $0 {start|stop|restart}"
        exit 1
        ;;
esac

exit 0
