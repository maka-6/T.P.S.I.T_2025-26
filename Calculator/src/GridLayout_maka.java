/*
* Autore: Makaoui Youness
* Classe: 4G
* Luogo: Lab 53bis
* Data: 23/01/2026
* Descrizione: Creazione di un frame estendendo la classe JFrame GridLayout
*/

import java.awt.*;
import javax.swing.*;

public class GridLayout_maka extends JFrame {
	
	
	JTextField email = new JTextField( 40 );
	JTextField password = new JTextField( 40 );
	JTextField confermaPassword = new JTextField( 40 );
	JButton register = new JButton("Regstrati");
	
	public GridLayout_maka() {
		
		super("form super figo!!");
		setLayout(new GridLayout(4,1));
		add(email);
		add(password);
		add(confermaPassword);
		add(register);
		setSize(400,600);
		setResizable(false);
		setVisible(true);
	}
}