import edu.princeton.cs.algs4.MinPQ;
import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;

public class Board {
    private final int[][] tiles;
    private final int n;
    
    public Board(int[][] tiles) {
        this.n = tiles.length;
        this.tiles = new int[n][n];
        for (int i = 0; i < n; i++) {
            System.arraycopy(tiles[i], 0, this.tiles[i], 0, n);
        }
    }
    
    public int dimension() {
        return n;
    }
    
    public int hamming() {
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (tiles[i][j] != 0 && tiles[i][j] != i * n + j + 1) {
                    count++;
                }
            }
        }
        return count;
    }
    
    public int manhattan() {
        int distance = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int value = tiles[i][j];
                if (value != 0) {
                    int targetX = (value - 1) / n;
                    int targetY = (value - 1) % n;
                    distance += Math.abs(i - targetX) + Math.abs(j - targetY);
                }
            }
        }
        return distance;
    }
    
    public boolean isGoal() {
        return hamming() == 0;
    }
    
    public Iterable<Board> neighbors() {
        List<Board> neighbors = new ArrayList<>();
        int blankX = -1, blankY = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (tiles[i][j] == 0) {
                    blankX = i;
                    blankY = j;
                    break;
                }
            }
        }
        
        int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int[] dir : directions) {
            int newX = blankX + dir[0];
            int newY = blankY + dir[1];
            if (newX >= 0 && newX < n && newY >= 0 && newY < n) {
                int[][] copy = copyTiles();
                copy[blankX][blankY] = copy[newX][newY];
                copy[newX][newY] = 0;
                neighbors.add(new Board(copy));
            }
        }
        return neighbors;
    }
    
    public Board twin() {
        int[][] twinTiles = copyTiles();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (twinTiles[i][j] != 0 && twinTiles[i][j + 1] != 0) {
                    int temp = twinTiles[i][j];
                    twinTiles[i][j] = twinTiles[i][j + 1];
                    twinTiles[i][j + 1] = temp;
                    return new Board(twinTiles);
                }
            }
        }
        return new Board(twinTiles);
    }
    
    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Board board = (Board) obj;
        return Arrays.deepEquals(tiles, board.tiles);
    }
    
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(n).append("\n");
        for (int[] row : tiles) {
            for (int tile : row) {
                sb.append(String.format("%2d ", tile));
            }
            sb.append("\n");
        }
        return sb.toString();
    }
    
    private int[][] copyTiles() {
        int[][] copy = new int[n][n];
        for (int i = 0; i < n; i++) {
            System.arraycopy(tiles[i], 0, copy[i], 0, n);
        }
        return copy;
    }
}
