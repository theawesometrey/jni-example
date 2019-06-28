package jni.example;

import java.util.Objects;

public class Pair {

    private final double left;
    private final double right;

    public static Pair create(double left, double right) {
        return new Pair(left, right);
    }

    public Pair(double left, double right) {
        this.left = left;
        this.right = right;
    }

    public double getLeft() {
        return left;
    }

    public double getRight() {
        return right;
    }

    public double[] toArray() {
        return new double[]{left, right};
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Pair pair = (Pair) o;
        return Double.compare(pair.left, left) == 0 &&
                Double.compare(pair.right, right) == 0;
    }

    @Override
    public int hashCode() {
        return Objects.hash(left, right);
    }
}
