import edu.princeton.cs.algs4.Point2D;
import edu.princeton.cs.algs4.RectHV;
import java.util.ArrayList;
import java.util.List;

public class KdTree {
    private static class Node {
        private final Point2D point;
        private final RectHV rect;
        private Node left, right;
        private final boolean vertical;
        
        public Node(Point2D point, RectHV rect, boolean vertical) {
            this.point = point;
            this.rect = rect;
            this.vertical = vertical;
        }
    }
    
    private Node root;
    private int size;
    
    public KdTree() {
        this.root = null;
        this.size = 0;
    }
    
    public boolean isEmpty() {
        return size == 0;
    }
    
    public int size() {
        return size;
    }
    
    public void insert(Point2D p) {
        if (p == null) throw new IllegalArgumentException();
        root = insert(root, p, 0, new RectHV(0, 0, 1, 1));
    }
    
    private Node insert(Node node, Point2D p, int depth, RectHV rect) {
        if (node == null) {
            size++;
            return new Node(p, rect, depth % 2 == 0);
        }
        if (node.point.equals(p)) return node;
        
        if ((node.vertical && p.x() < node.point.x()) || (!node.vertical && p.y() < node.point.y())) {
            node.left = insert(node.left, p, depth + 1, rect);
        } else {
            node.right = insert(node.right, p, depth + 1, rect);
        }
        return node;
    }
    
    public boolean contains(Point2D p) {
        if (p == null) throw new IllegalArgumentException();
        return contains(root, p);
    }
    
    private boolean contains(Node node, Point2D p) {
        if (node == null) return false;
        if (node.point.equals(p)) return true;
        
        if ((node.vertical && p.x() < node.point.x()) || (!node.vertical && p.y() < node.point.y())) {
            return contains(node.left, p);
        } else {
            return contains(node.right, p);
        }
    }
    
    public void draw() {
        draw(root);
    }
    
    private void draw(Node node) {
        if (node == null) return;
        node.point.draw();
        draw(node.left);
        draw(node.right);
    }
    
    public Iterable<Point2D> range(RectHV rect) {
        if (rect == null) throw new IllegalArgumentException();
        List<Point2D> pointsInRange = new ArrayList<>();
        range(root, rect, pointsInRange);
        return pointsInRange;
    }
    
    private void range(Node node, RectHV rect, List<Point2D> pointsInRange) {
        if (node == null || !rect.intersects(node.rect)) return;
        if (rect.contains(node.point)) pointsInRange.add(node.point);
        range(node.left, rect, pointsInRange);
        range(node.right, rect, pointsInRange);
    }
    
    public Point2D nearest(Point2D p) {
        if (p == null) throw new IllegalArgumentException();
        if (root == null) return null;
        return nearest(root, p, root.point);
    }
    
    private Point2D nearest(Node node, Point2D p, Point2D nearest) {
        if (node == null) return nearest;
        if (p.distanceSquaredTo(node.point) < p.distanceSquaredTo(nearest)) {
            nearest = node.point;
        }
        
        if (node.left != null && node.left.rect.distanceSquaredTo(p) < p.distanceSquaredTo(nearest)) {
            nearest = nearest(node.left, p, nearest);
        }
        if (node.right != null && node.right.rect.distanceSquaredTo(p) < p.distanceSquaredTo(nearest)) {
            nearest = nearest(node.right, p, nearest);
        }
        
        return nearest;
    }
}
