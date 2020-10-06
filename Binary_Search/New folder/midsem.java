



import java.text.SimpleDateFormat;
import java.util.*;

public class midsem {
	
	abstract class User
	{
		int userId;
		String name;
		Date dob;
		String address;
		String pan;			
		
		User(int a,String b, Date c, String d, String e)
		{
			userId=a;
			name=b;
			dob=c;
			address=d;
			pan=e;			
		}
	}

	class admin extends User
	{
		Date doj;
		int salary;
		String permissibleop;	
		
		admin(int a,String b, Date c, String d, String e,Date f, int g, String h)
		{
			super(a,b,c,d,e);
			doj=f;
			salary=g;
			permissibleop=h;
		}
		
	}
	class general extends User
	{
		Date doj;
		int salary;
		String dutyhour;
		
		general(int a,String b, Date c, String d, String e,Date f, int g, String h)
		{
			super(a,b,c,d,e);
			doj=f;
			salary=g;
			dutyhour=h;
		}
		
		
	}
	
	abstract class item
	{
		String code;
		int price;
		int availableqty;
		ArrayList<item> list=new ArrayList<item>(); 
		
		void set(String a,int p,int q)
		{
			code=a;
			price=p;
			availableqty=q;
		}
		
		abstract void addnewstock(item i);
		abstract void deletestock(String code);
		abstract void modifystock(String code);
	}

	class fooditem extends item
	{
		Scanner sc=new Scanner(System.in);
		Date doexpiry;
		void addnewstock(item i)
		{
			list.add(i);
		}
		void deletestock(String code)
		{
			Iterator itr=list.iterator();
			while(itr.hasNext())
			{
				if (code == itr.next())
					itr.remove();
			}			
		}
		void modifystock(String code)
		{
			Iterator itr=list.iterator();
			while(itr.hasNext())
			{
				if (code == itr.next())
					{			
						System.out.println("Enter new price and available quantity:");
						int pp=sc.nextInt();
						int qq=sc.nextInt();
						set(code,pp,qq);
					}
			}
				
		}
		
		void sellitem(String code, int q)
		{
			Iterator itr=list.iterator();
			while(itr.hasNext())
			{
				if (code == itr.next())
					availableqty--;
			}	
		}
		void returnitem(String code, int q)
		{
			Iterator itr=list.iterator();
			while(itr.hasNext())
			{
				if (code == itr.next())
				{
					if(code.startsWith("F"))
					{
						System.out.println("Can't return food items.");
					}
					else
						modifystock(code);					
				}
					
			
			
		}
		void displaystock (String code)
		{
			System.out.println("code:"+code+" price:"+price+" available quantity:"+availableqty);
		}
		void displaysell(Date start, Date end)
		{
			
		}
		
	}
	
	class nonfooditem extends item
	{
		Scanner sc=new Scanner(System.in);
		
		int returncount;
		
		void addnewstock(item i)
		{
			list.add(i);
		}
		void deletestock(String code)
		{
			Iterator itr=list.iterator();
			while(itr.hasNext())
			{
				if (code == itr.next())
					itr.remove();
			}			
		}
		void modifystock(String code)
		{
			Iterator itr=list.iterator();
			while(itr.hasNext())
			{
				if (code == itr.next())
					{			
						System.out.println("Enter new price and available quantity:");
						int pp=sc.nextInt();
						int qq=sc.nextInt();
						set(code,pp,qq);
					}
			}
				
		}
		
		void sellitem(String code, int q)
		{
			Iterator itr=list.iterator();
			while(itr.hasNext())
			{
				if (code == itr.next())
					availableqty--;
			}	
		}
		void returnitem(String code, int q)
		{
			Iterator itr=list.iterator();
			while(itr.hasNext())
			{
				if (code == itr.next())
				{
					if(code.startsWith("F"))
					{
						System.out.println("Can't return food items.");
					}
					else
						modifystock(code);					
				}
					
			}	
		}
		void displaystock (String code)
		{
			System.out.println("code:"+code+" price:"+price+" available quantity:"+availableqty);
		}
		void displaysell(Date start, Date end)
		{
			
		}
	}
	
	public class sell
	{
		Date dos;
		String code;
		int quantity;
		int returnamt;
	}
	public class Return
	{
		Date dor;
		String code;
		int quantity;
		int returnamt;
	}

	
	public static void main(String[] args) 
	{
		SimpleDateFormat ss=new SimpleDateFormat("dd-mm-yyyy");
		ArrayList<admin> adList=new ArrayList<admin>(); 
		adList.add(new admin(123,"Manojit",ss.parse("01-01-1975"),"assam","abc12",ss.parse("01-01-2019"),100000,"all"));
		adList.add(new admin(134,"Ram",ss.parse("01-01-1972"),"assam","abd16",ss.parse("01-01-2019"),10000,"all"));
		adList.add(new admin(156,"Shyam",ss.parse("01-01-1976"),"assam","abe72",ss.parse("01-01-2019"),50000,"all"));
		
		ArrayList<general> genList=new ArrayList<general>(); 
		genList.add(new general(123,"Manu",ss.parse("01-01-1975"),"assam","abc12",ss.parse("01-01-2019"),100000,"4"));
		genList.add(new general(123,"Kanu",ss.parse("01-01-1975"),"assam","adn12",ss.parse("01-01-2019"),10000,"5"));
		genList.add(new general(123,"Banu",ss.parse("01-01-1975"),"assam","akl92",ss.parse("01-01-2019"),70000,"6"));
		
		
		Scanner sc=new Scanner(System.in);
		if(args[0]=="Admin")
		{
			if(adList.contains(args[1]))
			{
			
				System.out.println("1. Add new stock\n2. Delete stock\n3. Modify stock\n");
				int x=sc.nextInt();
				switch(x)
				{
					case 1: System.out.println("Enter code, price and available quantity:");
							String c=sc.nextLine();
							int p=sc.nextInt();
							int q=sc.nextInt();
							item f;   //reference to item
							//fooditem f=new fooditem();
							f.set(c, p, q);
							if(c.startsWith("F"))
							{
								f=new fooditem();
								f.addnewstock(f);
							}
							else
							{
								f=new nonfooditem();
								f.addnewstock(f);
							}
							break;
							
					case 2: System.out.println("Enter code to be deleted:");
							String k=sc.nextLine();
							f.deletestock(k);break;
							
					case 3: System.out.println("Enter code to be modified:");
							String l=sc.nextLine();
							f.modifystock(l);break;
				}
			}
			else
				System.out.println("You are not valid admin");
		}
		
		else if(args[0]=="General")
		{
			if(genList.contains(args[1]))
			{
				System.out.println("1. sell item\n2. return item\n3. display stock\n4. display sell\n");
				fooditem ff=new fooditem();
				int y=sc.nextInt();
				switch(y)
				{
					
					case 1: System.out.println("Enter code and quantity to be sold:"); 
							sell s1=new sell();
							String ss=sc.nextLine();
							int qq=sc.nextInt();
							ff.sellitem(ss,qq);break;
					case 2: ff.returnitem(ss,qq);break;
					case 3: System.out.println("Enter code to be displayed:");
							String z=sc.nextLine();
							ff.displaystock(z);break;
					case 4: ff.displaysell();break;
				}
			}
			else
				System.out.println("You are not valid");
		}
		
		

	}

}
