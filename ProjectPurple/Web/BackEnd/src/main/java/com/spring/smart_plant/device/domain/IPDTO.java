package com.spring.smart_plant.device.domain;

public class IpDTO {
	private String innerIp;

	/**
	 * 
	 */
	public IpDTO() {
		super();
		// TODO Auto-generated constructor stub
	}

	/**
	 * @param innerIp
	 */
	public IpDTO(String innerIp) {
		super();
		this.innerIp = innerIp;
	}

	public String getInnerIp() {
		return innerIp;
	}

	public void setInnerIp(String innerIp) {
		this.innerIp = innerIp;
	}
}
