package example;

import jni.example.Example;
import jni.example.Pair;
import org.testng.Assert;
import org.testng.annotations.Test;

public class ExampleNGTest {

    @Test
    public void testSq() {
        double[] array = new double[]{0.0, 1.0, 2.0};
        double[] expected = new double[] {0.0, 1.0, 4.0};
        Example.sq(array);
        for (int i = 0; i < array.length; ++i) {
            Assert.assertEquals(array[i], expected[i], 1e-12);
        }
    }

    @Test
    public void testNewArray() {
        int size = 5;
        double fill = 5.5;
        double[] array = Example.newArray(size, fill);
        Assert.assertEquals(array.length, size);
        for (int i = 0; i < size; ++i) {
            Assert.assertEquals(array[i], fill, 1e-12);
        }
    }

    @Test
    public void testNew2DArray() {
        int size1 = 5;
        int size2 = 3;
        double fill = 5.5;
        double[][] array = Example.new2DArray(size1, size2, fill);
        Assert.assertEquals(array.length, size1);
        for (int i = 0; i < size1; ++i) {
            Assert.assertEquals(array[i].length, size2);
            for (int j = 0; j < size2; ++j) {
                Assert.assertEquals(array[i][j], fill, 1e-12);
            }
        }
    }

    @Test
    public void testCopy() {
        Pair pair = Pair.create(234.3, 97973.3);
        Pair copy = Example.copy(pair);
        Assert.assertNotSame(copy, pair);
        Assert.assertEquals(copy, pair);
    }
}
