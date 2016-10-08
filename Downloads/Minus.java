package org.elsys.postfix.operations;
 
import org.elsys.postfix.Calculator;
 
public class Minus extends BinaryOperation implements Operation {
 
    public Minus(Calculator calculator, String token) {
        super(calculator, token);
    }
 
    @Override
    public double eval(Double value1, Double value2) {
        return value1 - value2;
    }
 
}
