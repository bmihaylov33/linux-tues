package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public abstract class UnaryOperation extends AbstractOperation{

	public UnaryOperation(Calculator calculator, String token) {
		super(calculator, token);
		// TODO Auto-generated constructor stub
	}

	@Override
	public void calculate() {
		
			Double value1 = getCalculator().popValue();
			Double result = eval(value1);

			getCalculator().addValue(result);
			
			System.out.println(result);
			
			(IndexOutOfBoundsException e) 
			// TODO Auto-generated catch block

			System.out.println("Error");
		
	}
	
	public abstract double eval(Double value1);
}
