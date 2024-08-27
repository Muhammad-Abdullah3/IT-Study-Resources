import java.util.Scanner;
import java.lang.Math;
class Shape {
    public double calcArea() {
        return 0;
    }
}
class Circle extends Shape {
    private double radius = 0;
    public void setRadius(double r)
    {
        radius = r;
    }
    public double calcArea() {
        return Math.PI * radius * radius;
    }
}
class Rectangle extends Shape {
    private double length = 0;
    private double width = 0;
    public void setLengthWidth(double l,double w) {
        length = l;
        width = w;
    }
    public double calcArea() {
        return length*width;
    }
}
class Triangle extends Shape {
    private double base = 0;
    private double height = 0;
    public void setBaseHeight(double b,double h) {
        base = b;
        height = h;
    }
    public double calcArea() {
        return (base*height)/2;
    }
}
public class Task1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Circle c1 = new Circle();
        System.out.println("Enter radius of the circle: ");
        double r = sc.nextDouble();
        c1.setRadius(r);
        System.out.println("Area of the circle = "+c1.calcArea());

        Rectangle r1 = new Rectangle();
        System.out.println("Enter length of the rectangle: ");
        double l = sc.nextDouble();
        System.out.println("Enter width of the rectangle: ");
        double w = sc.nextDouble();
        r1.setLengthWidth(l,w);
        System.out.println("Area of the Rectangle = "+r1.calcArea());

        Triangle t1 = new Triangle();
        System.out.println("Enter base of the triangle: ");
        double b = sc.nextDouble();
        System.out.println("Enter height of the triangle: ");
        double h = sc.nextDouble();
        t1.setBaseHeight(b,h);
        System.out.println("Area of the Triangle = "+t1.calcArea());
        sc.close();
    }

}
