import java.util.Arrays;
import java.util.ArrayList;

public class BruteCollinearPoints {
    private final ArrayList<LineSegment> segments;
    
    public BruteCollinearPoints(Point[] points) {
        if (points == null) throw new IllegalArgumentException("Argument is null");
        
        int n = points.length;
        Point[] copy = Arrays.copyOf(points, n);
        Arrays.sort(copy);
        
        for (int i = 0; i < n - 1; i++) {
            if (copy[i] == null) throw new IllegalArgumentException("Null point detected");
            if (copy[i].compareTo(copy[i + 1]) == 0) throw new IllegalArgumentException("Duplicate points detected");
        }
        
        segments = new ArrayList<>();
        
        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                for (int k = j + 1; k < n - 1; k++) {
                    for (int m = k + 1; m < n; m++) {
                        if (copy[i].slopeTo(copy[j]) == copy[i].slopeTo(copy[k]) &&
                            copy[i].slopeTo(copy[j]) == copy[i].slopeTo(copy[m])) {
                            Point[] collinear = {copy[i], copy[j], copy[k], copy[m]};
                            Arrays.sort(collinear);
                            segments.add(new LineSegment(collinear[0], collinear[3]));
                        }
                    }
                }
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