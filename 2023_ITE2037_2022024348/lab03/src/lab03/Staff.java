package lab03;

public class Staff {

	private String name;
	private int age;
	private String department = "None";
	private int workDays = 0;
	private int vacationDays = 20;
	
	public Staff(String name, int age) {
		this.name = name;
		this.age = age;
	}
	public Staff(String name, int age, String department, int workDays, int vacationDays) {
		this.name = name;
		this.age = age;
		this.department = department;
		this.workDays = workDays;
		this.vacationDays = vacationDays;
	}
	public String getter() {
		return this.name;
	}
	public void setter(Staff career) {
		this.department = career.department;
		this.workDays = career.workDays;
	}
	public boolean sameCareer(Staff career) {
		if(this.department.equals(career.department) && this.workDays == career.workDays) {
			return true;
		}
		else {
			return false;
		}
	}
	public String toString() {
		String tmp = "Name:" + this.name + ", Age" + this.age + ", Department:" + this.department + ", workDays" + this.workDays + "VacationDays:" + this.vacationDays;
		return tmp;
	}
	public void vacation(int vacationDays) {
		if(this.vacationDays < vacationDays) {
			System.out.println(this.name +", 남은 휴가 일 수 부족.");
		}
		else {
			this.vacationDays -= vacationDays;
			System.out.printf("%s, 휴가 " + vacationDays + " 사용, 남은 휴가 일수:%d\n", this.name, this.vacationDays);
		}
	}

}
