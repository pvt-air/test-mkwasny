<?php
session_start();
/* plik znaleziony na dysku w pracowni laboratoryjnej */

	class Model {
		
		private $username;
		private $password;
		
		public function __construct($username,$password) {
			$this->username=$username;
			$this->password=$password;
		}
		public function getPassword() {
			return $this->password;
		}
		
		public function getUsername() {
			return $this->username;
		}
		
		function connectBase($servername,$username,$password,$nazwa) {
			
			$login=$this->username;
			$pass=$this->password;
			echo $this->username;
			echo $this->password;
			$servername =$servername ;
			$username = $username;
			$password = $password;
			$nazwa = $nazwa;
	
			$mysqli = new mysqli($servername,$username,$password,'lukiii');
			/* check connection */
			if (mysqli_connect_errno()) {
				printf("Connect failed: %s\n", mysqli_connect_error());
				exit();
			}
			/* create a prepared statement */
			if ($stmt = $mysqli->prepare("SELECT * FROM $nazwa WHERE Login=? AND Haslo=?")) {
				/* bind parameters for markers */
				$stmt->bind_param("ss", $login,$pass);
				/* execute query */
				$stmt->execute();
				$stmt->store_result();
				$rows = $stmt->num_rows;
				$comm="";
				/* close statement */
				$stmt->close();
				$mysqli->close();
				if($rows>0)
				{
					#echo "Ten uzytkownik juz istnieje";
					$comm="True";
				}
				else {
					#echo "Ten uzytkownik jeszcze nie istnieje!! Zarejestruj sie!!!";
					$comm="False";
				}	
			}
			return $comm;
		}	
		
	}
?>