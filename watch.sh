#!/bin/bash

WATCH_DIR="./test"  # Replace with the path to your folder
BRANCH="main"       # Replace with your branch name

echo "Monitoring folder: $WATCH_DIR for new files..."

# Function to periodically sync the local repository
sync_repo() {
    while true; do
        echo "Syncing with remote repository..."
        git pull origin "$BRANCH"
        sleep 30  # Wait for 300 seconds (5 minutes)
    done
}

# Start the sync function in the background
sync_repo &

# Monitor the folder for file changes
fswatch -o "$WATCH_DIR" | while read event; do
    echo "Change detected, processing Git commands..."

    # Add, commit, and push changes
    git pull origin "$BRANCH"
    git add .
    git commit -m "Auto-commit: New changes detected"
    git push origin "$BRANCH"

    echo "Changes pushed to branch $BRANCH."
done
