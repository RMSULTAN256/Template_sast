#!/bin/bash

# Fetch the previous commit (required in CI environments like GitHub Actions)
git fetch --depth=2

# Get list of newly added files (A = "added" files)
NEW_FILES=$(git diff --name-only --diff-filter=A HEAD~1 HEAD)

if [ -n "$NEW_FILES" ]; then
  echo "New files detected:"
  echo "$NEW_FILES"
else
  echo "No new files detected."
fi