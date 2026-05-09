import java.util.*;

public class Solution {
    static class Node {
        int data;
        Node left, right;
        int height;
        Node(int d) {
            data = d;
            left = right = null;
            height = 0;
        }
    }

    static int height(Node node) {
        if (node == null) return -1;
        return node.height;
    }

    static Node rotateLeft(Node x) {
        Node y = x.right;
        Node T2 = y.left;
        y.left = x;
        x.right = T2;
        x.height = 1 + Math.max(height(x.left), height(x.right));
        y.height = 1 + Math.max(height(y.left), height(y.right));
        return y;
    }

    static Node rotateRight(Node y) {
        Node x = y.left;
        Node T2 = x.right;
        x.right = y;
        y.left = T2;
        y.height = 1 + Math.max(height(y.left), height(y.right));
        x.height = 1 + Math.max(height(x.left), height(x.right));
        return x;
    }

    static Node insert(Node root, int val) {
        if (root == null) {
            return new Node(val);
        }
        if (val < root.data) {
            root.left = insert(root.left, val);
        } else if (val > root.data) {
            root.right = insert(root.right, val);
        } else {
            return root;
        }
        root.height = 1 + Math.max(height(root.left), height(root.right));
        int bf = height(root.left) - height(root.right);
        if (bf > 1 && val < root.left.data) {
            return rotateRight(root);
        }
        if (bf < -1 && val > root.right.data) {
            return rotateLeft(root);
        }
        if (bf > 1 && val > root.left.data) {
            root.left = rotateLeft(root.left);
            return rotateRight(root);
        }
        if (bf < -1 && val < root.right.data) {
            root.right = rotateRight(root.right);
            return rotateLeft(root);
        }
        return root;
    }

    static void inOrder(Node root) {
        if (root == null) return;
        inOrder(root.left);
        System.out.print(root.data + "(BF=" + (height(root.left) - height(root.right)) + ") ");
        inOrder(root.right);
    }

    static void preOrder(Node root) {
        if (root == null) return;
        System.out.print(root.data + "(BF=" + (height(root.left) - height(root.right)) + ") ");
        preOrder(root.left);
        preOrder(root.right);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node root = null;
        for (int i = 0; i < n; i++) {
            root = insert(root, sc.nextInt());
        }
        int newVal = sc.nextInt();
        root = insert(root, newVal);
        inOrder(root);
        System.out.println();
        preOrder(root);
        System.out.println();
    }
}