package lab02;

import java.util.Scanner;

public class lab02 {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String input = scan.nextLine();
		int length = 0;
		for(int i = 0;i < input.length();++i) {
			char c = input.charAt(i);
			if(c == ' ') {
				++length;
			}
		}
		System.out.println("Name Length(Korean) : " + length);
		String[] arr = input.split(" ");
		for(int i = 0;i < length - 1;++i) {
			String s = arr[i].toUpperCase();
			System.out.printf(s.charAt(0) + ".");
		}
		String ch = arr[length - 1].toUpperCase();
		
		System.out.println(ch.charAt(0) + arr[length - 1].substring(1, arr[length - 1].length() - 1) + " submitted Homework.pdf");
		scan.close();
	}
}
