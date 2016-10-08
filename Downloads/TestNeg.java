package org.elsys.postfix.operations.test;

import static org.junit.Assert.*;

import org.elsys.postfix.Calculator;
import org.elsys.postfix.operations.Neg;
import org.junit.Test;

public class NegTest {

	@Test
	public final void testCalculate() {
		Calculator calculator = new Calculator();
		Neg neg = new Neg(calculator, "neg");
		calculator.addOperation(neg);
		// the plus operation gets its operands from the calculator
		// so we have to add them to the calculator's stack
		calculator.addValue(10);
		//calculator.addValue(5);
		// execute the operation
		neg.calculate();
		// the plus operation will put the result in the calculator's
		// stack so we get it from there
		assertEquals(-10, calculator.popValue(), 0.00001);
	}

}
