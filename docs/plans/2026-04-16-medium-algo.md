# Medium Algorithm Implementation Plan

> **For Claude:** REQUIRED SUB-SKILL: Use superpowers:executing-plans to implement this plan task-by-task.

**Goal:** Make the `--medium` strategy behave more like the PDF's expected `O(n√n)` chunk-based algorithm.

**Architecture:** Replace the current medium flow in phases. First, improve the `a -> b` phase so elements are pushed by chunk and reached from the nearest side of stack `a`. Then refine the `b -> a` phase so it no longer relies on repeated global-maximum extraction.

**Tech Stack:** C, linked-list stacks, existing push_swap operations.

---

### Task 1: Rework chunk push phase

**Files:**
- Modify: `push_swap_medium_algorithm.c`

**Step 1: Add chunk helpers**

Create helpers to:
- compute an integer chunk size near `sqrt(n)`
- find the nearest element of the active chunk from the top or bottom of stack `a`
- rotate `a` toward that element

**Step 2: Rewrite the `a -> b` phase**

Push chunk ranges in ascending index order instead of scanning with a linear counter.

**Step 3: Keep return phase stable**

Leave `b -> a` logic unchanged for now so the strategy remains functional while improving the first half.

**Step 4: Rebuild**

Run: `make re`

**Step 5: Verify behavior**

Run:
- `./push_swap --medium 5 4 3 2 1`
- `./push_swap --medium --bench 5 4 3 2 1`
