#!/bin/bash

WATCH_DIR="./test"  # Replace with the path to your folder
BRANCH="main"        # Replace with your branch name

echo "Monitoring folder: $WATCH_DIR for new files..."

fswatch -o "$WATCH_DIR" | while read event
do
    echo "Change detected, processing Git commands..."

    # Add, commit, and push changes
    git add .
    git commit -m "Auto-commit: New changes detected"
    git push origin "$BRANCH"

    echo "Changes pushed to branch $BRANCH."
done
