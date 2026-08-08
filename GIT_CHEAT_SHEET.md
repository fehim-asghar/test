# 🗺️ The Ultimate Git Map & Cheat Sheet

This is a complete map of every single Git command and concept you mastered today. Save this file, commit it, and keep it forever!

---

## 🛠️ Level 1: The Setup
*Setting up Git for the very first time on a new computer.*

- **`git config --global user.name "Your Name"`** → Signs your name to your work.
- **`git config --global user.email "email@example.com"`** → Attaches your email to your work.
- **`git init`** → Gives a normal folder a "Brain" (creates the hidden `.git` folder).

---

## 📦 Level 2: The Core Loop
*The commands you will use 50 times a day.*

- **`git status`** → The Radar. Tells you what files are changed, staged, or untracked.
- **`git add <file>`** → Puts a file into the "staging box" to prepare for saving.
- **`git add .`** → Puts *every* changed file into the box at once.
- **`git commit -m "message"`** → Tapes the box shut and permanently takes a snapshot of your code.
- **`git log --oneline`** → Shows your entire timeline of snapshots.

---

## 🌿 Level 3: Parallel Universes (Branching)
*How to build features without breaking the main game.*

- **`git branch`** → Lists all the universes/branches on your computer.
- **`git switch -c <name>`** → Creates a brand new branch and teleports you into it.
- **`git switch <name>`** → Teleports you between existing branches.
- **`git merge <name>`** → Glues another branch's code into the branch you are currently standing on.
- **`git branch -d <name>`** → Safely deletes a branch after you're done with it.

---

## ☁️ Level 4: The Cloud (GitHub)
*How to collaborate with teammates around the world.*

- **`git remote add origin <URL>`** → Links your local folder to a GitHub repository.
- **`git push`** → Uploads your local snapshots to GitHub.
- **`git pull origin <branch>`** → Downloads new snapshots from GitHub down to your laptop.
- **Pull Request (PR)** → A webpage on GitHub where your team reviews your code before merging it into `main`.

---

## 🧰 Level 5: The Senior Developer Toolkit
*How to fix mistakes and hide secrets.*

- **`git checkout <commit-ID>`** → Time Travel! Rewinds your files to exactly how they looked in the past (Detached HEAD).
- **`git revert <commit-ID>`** → The Safe Undo. Creates a *new* commit that does the exact opposite of the bad commit, keeping history safe.
- **`git stash`** → Magically sucks up your uncommitted, broken code and hides it in a secret pocket.
- **`git stash pop`** → Spits the hidden code out of the pocket back into your files.
- **`.gitignore`** → A magical file that makes any file listed inside it completely invisible to Git (perfect for hiding passwords!).
