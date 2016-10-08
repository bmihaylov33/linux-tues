package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public abstract class BinaryOperation extends AbstractOperation{

	public BinaryOperation(Calculator calculator, String token) {
		super(calculator, token);
		// TODO Auto-generated constructor stub
	}

	@Override
	public void calculate() {

			Double value1 = getCalculator().popValue();
			Double value2 = getCalculator().popValue();
			Double result = eval(value1, value2);
			
			getCalculator().addValue(result);
			
			System.out.println(result);
			
			(IndexOutOfBoundsException  e) 
			// TODO Auto-generated catch block
			
			System.out.println("error");
		
	}
	
	public abstract double eval(Double value1, Double value2);
}
