#!/bin/bash

# Default port
PORT=8008

# Parse command-line arguments
# Default port
PORT=8011
NUM_REQUESTS=1000

# Parse command-line arguments
while getopts "p:n:h" opt; do
  case $opt in
    p)
      PORT=$OPTARG
      ;;
    n)
      NUM_REQUESTS=$OPTARG
      ;;
    h)
      echo "Usage: $0 [-p port] [-n number_of_requests]"
      exit 1
      ;;
  esac
done

# URL to send requests to
URL="http://0.0.0.0:$PORT"

# Function to send a request
send_request() {
  curl -s -o /dev/null   "$URL"
}

# Time the requests
start_time=$(date +%s%3N)

# Send requests
for ((i=1; i<=NUM_REQUESTS; i++))
do
  send_request &
done

# Wait for all background jobs to finish
wait

end_time=$(date +%s%3N)
elapsed_time=$((end_time - start_time))

echo " All $NUM_REQUESTS requests completed $elapsed_time milliseconds."