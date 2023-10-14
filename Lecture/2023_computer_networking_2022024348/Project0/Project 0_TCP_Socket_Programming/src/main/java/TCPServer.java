import java.io.*;
import java.net.*;

public class TCPServer {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		String clientSentence;
		String capitalizedSentence;
		ServerSocket welcomeSocket = new ServerSocket(4348);
		
		while(true) {
			Socket connectionSocket = welcomeSocket.accept();
			
			BufferedReader inFromClient = new BufferedReader(new InputStreamReader(connectionSocket.getInputStream()));
			
			DataOutputStream outToClient = new DataOutputStream(connectionSocket.getOutputStream());
			
			clientSentence = inFromClient.readLine();
			capitalizedSentence = clientSentence.toUpperCase() + '\n';
			
			outToClient.writeBytes(capitalizedSentence);
		}
	}

}
