# Day 28: Tree: Huffman Decoding

## Problem Description
Huffman coding is a prefix-free encoding technique used for data compression. The goal is to decode a binary string (composed of '0's and '1's) back into its original text using a provided Huffman tree.

## Implementation Approach

### 1. Decoding Logic (`decode_huff`)
The decoding process follows a simple path traversal on the Huffman tree:
- **Starting Point**: Always begin at the `root` node.
- **Traversal**:
    - If the bit is `'0'`, move to the `left` child.
    - If the bit is `'1'`, move to the `right` child.
- **Leaf Detection**: A leaf node in a Huffman tree is identified by having both `left` and `right` children as `NULL`.
- **Action on Leaf**: 
    - Print the character (`data`) found at the leaf.
    - **Crucial Step**: Reset the current pointer back to the `root` to start decoding the next character from the subsequent bit.

### 2. Testing Infrastructure (Local)
To test the decoding function locally with any string (like "Rumpelstiltskin"), the following infrastructure was added:
- **Frequency Map**: Counts the occurrences of each character in the input string.
- **Min-Heap (Priority Queue)**: Stores nodes sorted by frequency. This is used to build the tree bottom-up by repeatedly merging the two least frequent nodes.
- **Tree Builder**: Merges nodes until a single root remains.
- **Encoder**: Generates bit-codes for each character by traversing the tree and then builds the binary string passed to the `decode_huff` function.

## How to Run
1. Compile the solution:
   ```bash
   gcc solution.c -o solution
   ```
2. Run with any input:
   ```bash
   echo "YourStringHere" | ./solution
   ```
