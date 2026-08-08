# 🎓 CS Day 1: Git & GitHub Interactive Learning Roadmap

## 👤 Student Info
- **Name:** fehim-asghar
- **Date Started:** August 8, 2026

---

## ✅ Lesson 1: Git Basics & Cloud Setup (COMPLETED)
- **Identity Config:** `git config --global user.name` & `git config --global user.email`
- **Repository Init:** `git init` (created `.git` brain directory)
- **Radar:** `git status` (tracked vs untracked files)
- **Staging Box:** `git add <file>`
- **Snapshot Commit:** `git commit -m "message"`
- **Timeline Log:** `git log`
- **GitHub Connection:** `git remote add origin <url>`
- **Branch Rename:** `git branch -M main`
- **Cloud Push:** `git push -u origin <branch>`
- **Key Concepts Learned:**
  - `KB` (Base 10, 1000 bytes) vs `KiB` (Base 2, 1024 bytes)

---

## ✅ Lesson 2: Branching, Merging & Conflicts (COMPLETED)
- **List Branches:** `git branch`
- **Create Branch:** `git branch <name>`
- **Switch Branch:** `git switch <name>`
- **Create & Switch:** `git switch -c <name>`
- **Merge Branch:** `git merge <name>` (Fast-forward merge)
- **Delete Merged Branch:** `git branch -d <name>`
- **Merge Conflicts:**
  - Triggered by editing the same line across branches
  - Decoded conflict markers (`<<<<<<< HEAD`, `=======`, `>>>>>>>`)
  - Solved PowerShell UTF-16LE binary file encoding issue
  - Resolved conflict manually, staged, and committed!

---

## ✅ Lesson 3: Collaboration & Pull Requests (PARTIAL)
- **Simulating Teamwork:** Created commits directly on the GitHub UI.
- **Pulling Code:** `git pull` to download teammate's code.
- **Unrelated Histories:** Encountered the "entirely different commit histories" error when creating a Pull Request.
- **Forced Merge:** `git pull origin main --allow-unrelated-histories`
- **The Ultimate Test:** Successfully escaped **Vim** using `:wq`! 🐉🗡️

## ⏳ Next Up: Finishing Lesson 3
- `git push` the newly merged history.
- Finally open that Pull Request on GitHub and merge it!
