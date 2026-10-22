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

---

## 💻 How ChronosKV Works (Live Terminal Execution)

When the project is fully completed, it compiles into a standalone executable. Running it launches an interactive database command-line shell directly inside your IDE console or terminal.

### 1. Launching the Database Engine
Upon boot, ChronosKV initializes the system memory arrays, wipes out garbage data, and automatically reloads previous records from the local disk:

```text
[ChronosKV] Initializing Database Engine...
[ChronosKV] Sweeping memory slots clean... Done.
[ChronosKV] Loading persistent data from database.db... Done (3 records loaded).

Welcome to ChronosKV Shell. Type HELP for commands.
chronos_kv> 
```

### 2. Live Data Operations (Demo Commands)
You can store, retrieve, and inspect data entries in real-time. The engine calculates indices under the hood and reports success statuses:

* **Storing Data (`SET`):**
  ```text
  chronos_kv> SET username rahul123
  [Success] Stored 'username' at memory array index: 4
  ```

* **Retrieving Data (`GET`):**
  ```text
  chronos_kv> GET username
  [Result] rahul123
  ```

* **Handling Missing Keys:**
  ```text
  chronos_kv> GET nonexistent_key
  [Error] Key not found in the system matrix.
  ```

### 3. Advanced Diagnostic Inspection (`DUMP`)
To prove to professors that the hashing logic and collision chaining are working seamlessly, you can execute a memory layout inspect command to see the internal array allocation layout:

```text
chronos_kv> DUMP
--- CURRENT HASH TABLE MEMORY MATRIX ---
Slot: EMPTY (NULL)
Slot: EMPTY (NULL)
Slot: EMPTY (NULL)
Slot: EMPTY (NULL)
Slot: [Key: "username" | Value: "rahul123"] ──▶ [Key: "abc" | Value: "collision_data"] ──▶ NULL
Slot: EMPTY (NULL)
Slot: EMPTY (NULL)
Slot: EMPTY (NULL)
Slot: EMPTY (NULL)
Slot: EMPTY (NULL)
----------------------------------------
```

### 4. Safe Shutdown & Disk Persistence (`EXIT`)
When you are done, typing `EXIT` triggers the persistence layer, flushing active RAM chunks into a physical database file before wiping memory records clean to ensure no resource leaks:

```text
chronos_kv> EXIT
[ChronosKV] Shutting down database engine safely...
[ChronosKV] Saving all memory nodes to disk (database.db)... Done.
[ChronosKV] Freeing allocated heap memory bytes... Clean.

Process finished with exit code 0
```



