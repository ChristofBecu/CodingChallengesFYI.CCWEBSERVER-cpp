#!/bin/bash

# URL to send requests to
URL="http://0.0.0.0:8011"

# Number of requests
NUM_REQUESTS=1000

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