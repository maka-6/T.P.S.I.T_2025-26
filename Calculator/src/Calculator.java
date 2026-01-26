/*
* Autore: Makaoui Youness
* Classe: 4G
* Luogo: Lab 53bis
* Data: 23/01/2026
* Descrizione: Creazione di un frame estendendo la classe JFrame GridLayout
*/

import javax.swing.*;
import java.awt.*;

public class Calculator extends JFrame {

	JPanel northPanel;
	JTextField num1;
	JTextField num2;

	JPanel buttons;

	JPanel historyPanel;
	JTextArea history;

	JPanel resultPanel;
	JTextField result;
	
	public Calculator () {
		// creazione calcolatrice
		super("Calculator PRO MAX");
		setSize(500,500);
		setLayout(new BorderLayout());

		// in alto
		num1 = new JTextField(20);
		num2 = new JTextField(20);
		northPanel = new JPanel(new BorderLayout());
		northPanel.add(num1, BorderLayout.WEST);
		northPanel.add(num2, BorderLayout.EAST);
		add(northPanel, BorderLayout.NORTH);

		// centro
		buttons = new JPanel(new BorderLayout());
		buttons.add(createOperatorNumbersPanel(), BorderLayout.CENTER);
		add(buttons, BorderLayout.CENTER);

		// destra
		history = new JTextArea(10,5);
		historyPanel = new JPanel(new BorderLayout());
		historyPanel.add(history, BorderLayout.CENTER);
		add(historyPanel, BorderLayout.EAST);

		// sud
		result = new JTextField(20);
		resultPanel = new JPanel(new BorderLayout());
		resultPanel.add(result, BorderLayout.CENTER);
		add(resultPanel, BorderLayout.SOUTH);

		setVisible(true);
	}

	private JPanel createOperatorNumbersPanel() {
		// pannello numeri e operatori
		JPanel panelOperatorNumbers = new JPanel(new GridLayout(4, 4));

		String[] numbersOperators = {"0", "1", "2", "+", "3","4","5","-","6","7","8", "*", "9", "/", "c","="};

		for (String text : numbersOperators) {
			JButton b = new JButton(text);
			panelOperatorNumbers.add(b);
		}

		return panelOperatorNumbers;
	}
}