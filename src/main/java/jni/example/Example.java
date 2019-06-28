package jni.example;

public class Example {

    static {
        System.loadLibrary("example");
    }

    public static native void sq(double[] array);

    public static native double[] newArray(int size, double fill);

    public static native double[][] new2DArray(int size1, int size2, double fill);

    public static native Pair copy(Pair pair);
}
