package jni.example;

import java.io.File;
import java.util.Arrays;

public class Example {

    static {
        System.load(new File("build/libs/jni_example_Example/shared/libjni_example_Example.so").getAbsolutePath());
    }

    public static native void sq(double[] array);

    public static void main(String[] args) {
        double[] array = new double[]{0.0, 1.0, 2.0};
        Arrays.stream(array).forEach(System.out::println);
        sq(array);
        Arrays.stream(array).forEach(System.out::println);
    }
}
