import edu.princeton.cs.algs4.MinPQ;
import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;



public class Solver {
    private final List<Board> solution;
    private final int moves;
    
    public Solver(Board initial) {
        if (initial == null) throw new IllegalArgumentException();
        MinPQ<SearchNode> pq = new MinPQ<>();
        pq.insert(new SearchNode(initial, 0, null));
        
        while (!pq.isEmpty()) {
            SearchNode node = pq.delMin();
            if (node.board.isGoal()) {
                solution = new ArrayList<>();
                while (node != null) {
                    solution.add(0, node.board);
                    node = node.previous;
                }
                moves = solution.size() - 1;
                return;
            }
            for (Board neighbor : node.board.neighbors()) {
                if (node.previous == null || !neighbor.equals(node.previous.board)) {
                    pq.insert(new SearchNode(neighbor, node.moves + 1, node));
                }
            }
        }
        solution = null;
        moves = -1;
    }
    
    private static class SearchNode implements Comparable<SearchNode> {
        private final Board board;
        private final int moves;
        private final SearchNode previous;
        private final int priority;
        
        public SearchNode(Board board, int moves, SearchNode previous) {
            this.board = board;
            this.moves = moves;
            this.previous = previous;
            this.priority = board.manhattan() + moves;
        }
        
        @Override
        public int compareTo(SearchNode other) {
            return Integer.compare(this.priority, other.priority);
        }
    }
    
    public boolean isSolvable() {
        return solution != null;
    }
    
    public int moves() {
        return moves;
    }
    
    public Iterable<Board> solution() {
        return solution;
    }
}
