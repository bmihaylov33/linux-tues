package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;
 
public class Neg extends UnaryOperation implements Operation {
 
    public Neg(Calculator calculator, String token) {
        super(calculator, token);
    }
 
    @Override
    public double eval(Double value1) {
        return (-value1);
    }
 
}
