package example;

import jni.example.Example;
import org.testng.Assert;
import org.testng.annotations.Test;

public class ExampleNGTest {

    @Test
    public void testSq() {
        double[] array = new double[]{0.0, 1.0, 2.0};
        double[] expected = new double[] {0.0, 1.0, 4.0};
        Example.sq(array);
        for (int i = 0; i < array.length; ++i) {
            Assert.assertEquals(expected[i], array[i], 1e-12);
        }
    }
}
