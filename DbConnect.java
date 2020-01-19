import java.io.*;
import java.sql.*;

public class DbConnect {
    public static void main(String args[]) throws Exception
    {
        String url = "jdbc:mysql://localhost/student";
        String uname = "root";
        String pass = "";
        String query;
        Class.forName("com.mysql.jdbc.Driver");
        try
        {
        	Connection con = DriverManager.getConnection(url,uname,pass);
        	Statement st = con.createStatement();

		while(true)
		{
			System.out.print("1.Select\t2.Delete\t3.Update\t4.Insert\t5.Exit: ");
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			int opt = Integer.parseInt(br.readLine());
			switch(opt)
			{
				case 1:
				query = "select * from student";
            			ResultSet rs = st.executeQuery(query);
            			String userData = "";
            			while(rs.next())
            			{
              				userData = rs.getString(1)+" "+rs.getString(2)+" "+rs.getString(3);
              				System.out.println(userData);
            			}
				System.out.println("\n");
				break;

				case 2:
				System.out.println("Whose record must be deleted?");
				query = "delete from student where name = '" + br.readLine() + "'";
				st.executeUpdate(query);
				System.out.println("\n");
				break;

				case 3:
				System.out.println("Whose marks to increment?");
				String name = br.readLine();
				query = "update student set marks = marks + 1 where name = '" + name + "'";
				st.executeUpdate(query);
				System.out.println("\n");
				break;

				case 4:
				System.out.println("Enter name:");
				name = br.readLine();
				System.out.println("Enter marks:");
				int marks = Integer.parseInt(br.readLine());
				System.out.println("Enter age:");
				int age = Integer.parseInt(br.readLine());
				query = "insert into student values('" + name + "',"+ marks +","+ age +")";
				st.executeUpdate(query);
				System.out.println("\n");
				break;
				
				case 5:
				return;				

				default:
				System.out.println("Invalid option\n");
           		}
		}
        }
        catch(Exception e) 
       	{
           	System.out.println(e);
        }
                
    }
    
}
