import java.util.Arrays;
import java.util.ArrayList;

public class FastCollinearPoints {
    private final ArrayList<LineSegment> segments;
    
    public FastCollinearPoints(Point[] points) {
        if (points == null) throw new IllegalArgumentException("Argument is null");
        
        int n = points.length;
        Point[] copy = Arrays.copyOf(points, n);
        Arrays.sort(copy);
        
        for (int i = 0; i < n - 1; i++) {
            if (copy[i] == null) throw new IllegalArgumentException("Null point detected");
            if (copy[i].compareTo(copy[i + 1]) == 0) throw new IllegalArgumentException("Duplicate points detected");
        }
        
        segments = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            Point origin = copy[i];
            Point[] sortedPoints = Arrays.copyOf(copy, n);
            Arrays.sort(sortedPoints, origin.slopeOrder());
            
            int start = 1;
            while (start < n) {
                int end = start;
                while (end < n && origin.slopeTo(sortedPoints[start]) == origin.slopeTo(sortedPoints[end])) {
                    end++;
                }
                if (end - start >= 3) {
                    Point[] collinear = new Point[end - start + 1];
                    collinear[0] = origin;
                    for (int j = start; j < end; j++) {
                        collinear[j - start + 1] = sortedPoints[j];
                    }
                    Arrays.sort(collinear);
                    if (origin.compareTo(collinear[0]) == 0) {
                        segments.add(new LineSegment(collinear[0], collinear[collinear.length - 1]));
                    }
                }
                start = end;
            }
        }
    }
    
    public int numberOfSegments() {
        return segments.size();
    }
    
    public LineSegment[] segments() {
        return segments.toArray(new LineSegment[0]);
    }
}
