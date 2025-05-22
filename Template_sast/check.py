import subprocess

def detect_new_files():
    # Fetch previous commits (required in CI)
    subprocess.run(["git", "fetch", "--depth=2"], check=True)
    
    # Get list of newly added files
    result = subprocess.run(
        ["git", "diff", "--name-only", "--diff-filter=A", "HEAD~1", "HEAD"],
        capture_output=True,
        text=True
    )
    
    new_files = result.stdout.strip().split('\n') if result.stdout else []
    
    if new_files and new_files[0]:
        print("New files detected:")
        for file in new_files:
            print(file)
        # Add your logic here
    else:
        print("No new files detected.")

if __name__ == "__main__":
    detect_new_files()