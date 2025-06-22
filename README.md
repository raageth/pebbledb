# pebbledb

**pebbledb** is a lightweight key-value store implemented in C++. It is inspired by the Log-Structured Merge Tree (LSM Tree) architecture used in [RocksDB](https://github.com/facebook/rocksdb), a high-performance embedded database developed by Facebook.

This project is a personal learning initiative to deepen my understanding of modern storage engine designs. It draws direct inspiration from a RocksDB-based KV store I encountered during my time at ByteDance.

While working with backend infrastructure at ByteDance, I had the opportunity to explore a custom key-value store built on top of RocksDB. Fascinated by its performance characteristics and architectural decisions, I began building **pebbledb** to replicate those core ideas from scratch and to better understand concepts like WALs, MemTables, SSTables, and compaction.

> References
> - [LSM Tree](https://medium.com/@mndpsngh21/understanding-the-log-structured-merge-lsm-tree-a-deep-dive-into-efficient-data-storage-d7ef3a7562ba)