# 🧪 c11tester Test Suite

This repo contains test programs to validate a modified `c11tester` that reports **all** non-atomic data races.

## 📁 File Naming

- `n-*.cc` → No data races (used to test for false positives)
- `rw*.cc` → Read/Write race tests
- `ww*.cc` → Write/Write race tests

## ✅ No-Race Tests

| File             | Description                          |
|------------------|--------------------------------------|
| `n-rr.cc`        | Read/read on shared memory (safe)    |
| `n-localwr.cc`   | Writes to thread-local data          |
| `n-noshare.cc`   | No shared memory access              |
| `n-joinwr.cc`    | Writes after thread join             |
| `n-syncwr.cc`    | Synchronized write access            |

## ⚠️ Race Tests

| File             | Description                          |
|------------------|--------------------------------------|
| `rw2.cc`         | Read/write race, 2 threads           |
| `rw2vars.cc`     | Race on 2 shared variables           |
| `rw3vars.cc`     | Race on 3 variables                  |
| `ww5.cc`         | Write/write race, 5 threads          |
| `ww50.cc`        | Stress test: write/write, 50 threads |
