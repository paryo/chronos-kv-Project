# ChronosKV ⏳

A pure, high-performance **In-Memory Key-Value Database Engine** built completely from scratch in **ISO C**. This software engine is architected to showcase core low-level programming proficiencies, clean dynamic memory manipulation, and robust system-level software engineering practices tailored for advanced academic portfolios.

---

## 🏛️ System Architecture & Workflow

ChronosKV maps human-readable arbitrary string lookup payloads into bounded memory segments across a deterministic hash space, handling structural collisions using linked-list pointer chains.

```text
 User Interface (CLI/API)
           │
           ▼ (String Data)
   ┌──────────────┐
   │ Hashing Engine│ ──▶ ASCII Summation & Compression (% TABLE_SIZE)
   └───────┬──────┘
           │
           ▼ (Computed Array Slot Index: 0-9)
   ┌────────────────────────────────────────────────────────┐
   │ Hash Table Master Control Layer (Array of Pointers)     │
   └─┬─────┬─────┬─────┬─────┬──────────┬─────┬─────┬─────┬───┘
     │ 0 │ 1 │ 2 │ 3 │ 4 │   5    │ 6 │ 7 │ 8 │ 9 │
     └───┴───┴───┴───┴───┴────│─────┴───┴───┴───┴───┘
                              ▼ (Memory Address Reference: e.g., 0x7FFF)
                     ┌──────────────────┐
                     │ Heap Node Block  │ ──▶ [ Key: "username" | Value: "rahul123" ]
                     ├──────────────────┤
                     │ Pointer Hook     │ ──▶ struct key_value* next ──▶ NULL / Next Node
                     └──────────────────┘
```

---

## 🛠️ Operational Core Features

### 1. Deterministic String Hashing (`Step 2`)
Converts dynamic string keys into static bounded matrix indexes using character-by-character ASCII summation compressed under a modulo algorithm (`% TABLE_SIZE`). This guarantees reliable O(1) lookup complexity mapping.

### 2. Isolated Allocation Safeguards (`Step 3 & 4`)
Utilizes explicit operating system directives (`malloc`) to claim memory from the RAM's dynamic Heap pool at runtime. Features defensive validation steps (`if node == NULL`) to trap memory allocation crashes, ensuring high fault tolerance.

### 3. Read-Only Memory Contracts
Implements defensive pointer qualifiers (`const char*`) across search and write sequences to prevent accidental data corruption inside core registers, maintaining structural immutability during database access.

---

## 💾 Core Specifications & Memory Footprint

* **Language Standard:** Pure ISO C (No external third-party matrix libraries)
* **Maximum Key Boundary:** 50 Bytes (`KEY_SIZE`)
* **Maximum Value Payload:** 100 Bytes (`VALUE_SIZE`)
* **Default Table Slot Density:** 10 Fixed Buckets (`TABLE_SIZE`)

---

## 🚀 The Multi-Phase Project Roadmap

* [x] **Phase 1: Foundation Data Matrix Layout** – Defined the foundational structural data nodes.
* [x] **Phase 2: Summation Hashing Module** – Built the raw byte converter for lookup arrays.
* [x] **Phase 3: Clean Boot Allocator Array** – Formulated global tracking boards to flush garbage values.
* [x] **Phase 4: Dynamic SET Engine** – Deployed run-time heap reservation routines via `malloc`.
* [x] **Phase 5: Pointer-Evaluation GET Engine** – Engineered the O(1) value retrieval stack via string comparisons.
* [ ] **Phase 6: Advanced DSA Collision Chaining** – Implementing dynamic linked-list hooks to intercept slot collisions.
* [ ] **Phase 7: Persistence Binary Engine** – Designing native disk write/read loops (`fwrite`, `fread`) to dump data into permanent `.db` files.
* [ ] **Phase 8: Interactive Terminal Interface** – Constructing a live shell prompt environment (`chronos_kv> `) with zero-leak resource cleanup.

---

## 🔮 The Next Milestone: Custom 2D Retro Game Engine

Upon the completion of **ChronosKV**, this architecture will transition as the foundational storage core for a **Massive 45-Day Custom 2D Retro Game Engine & Playable RPG from Scratch**. 

The upcoming project will be engineered entirely in Pure C utilizing the low-level **SDL2 (Simple DirectMedia Layer)** hardware interface layer to drive:
* Hardwired 60 FPS Delta-Time Game Loops & Double-Buffered Visual Matrices.
* Raw Tilemap Parsers from binary text layouts.
* Native Axis-Aligned Bounding Box (AABB) physics and collision dynamics.
* Multi-State Enemy AI finite logic engines.
