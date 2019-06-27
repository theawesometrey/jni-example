package jni.example;

public class Example {

    static {
        System.loadLibrary("example");
    }

    public static native void sq(double[] array);
}
