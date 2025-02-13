
import edu.princeton.cs.algs4.WeightedQuickUnionUF;

// Percolation class to model the percolation system
public class Percolation {
    private final int n;
    private final boolean[][] grid;
    private final WeightedQuickUnionUF uf;
    private final int topVirtual;
    private final int bottomVirtual;
    private int openSites;

    public Percolation(int n) {
        if (n <= 0) throw new IllegalArgumentException("Grid size must be greater than 0");
        this.n = n;
        grid = new boolean[n][n];
        uf = new WeightedQuickUnionUF(n * n + 2);
        topVirtual = n * n;
        bottomVirtual = n * n + 1;
        openSites = 0;
    }

    private int index(int row, int col) {
        return (row - 1) * n + (col - 1);
    }

    public void open(int row, int col) {
        validate(row, col);
        if (grid[row - 1][col - 1]) return;
        grid[row - 1][col - 1] = true;
        openSites++;
        int current = index(row, col);

        if (row == 1) uf.union(current, topVirtual);
        if (row == n) uf.union(current, bottomVirtual);

        if (row > 1 && isOpen(row - 1, col)) uf.union(current, index(row - 1, col));
        if (row < n && isOpen(row + 1, col)) uf.union(current, index(row + 1, col));
        if (col > 1 && isOpen(row, col - 1)) uf.union(current, index(row, col - 1));
        if (col < n && isOpen(row, col + 1)) uf.union(current, index(row, col + 1));
    }

    public boolean isOpen(int row, int col) {
        validate(row, col);
        return grid[row - 1][col - 1];
    }

    public boolean isFull(int row, int col) {
        validate(row, col);
        return uf.find(index(row, col)) == uf.find(topVirtual);
    }

    public int numberOfOpenSites() {
        return openSites;
    }

    public boolean percolates() {
        return uf.find(topVirtual) == uf.find(bottomVirtual);
    }

    private void validate(int row, int col) {
        if (row < 1 || row > n || col < 1 || col > n) {
            throw new IllegalArgumentException("Row and Column indices out of bounds");
        }
    }
}