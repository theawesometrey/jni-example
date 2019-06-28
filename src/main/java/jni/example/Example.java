package jni.example;

import java.io.IOException;

public class Example {

    static {
        try {
            NativeUtils.loadLibraryFromJar("/libexample.so");
        } catch(IOException ex) {
            throw new RuntimeException(ex);
        }
    }

    public static native void sq(double[] array);

    public static native double[] newArray(int size, double fill);

    public static native double[][] new2DArray(int size1, int size2, double fill);

    public static native Pair copy(Pair pair);
}
