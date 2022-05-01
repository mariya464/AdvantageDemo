Action()
{

	lr_start_transaction("open_site");

	/*Connection ID 0 received buffer WebSocketReceive0*/

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_set_user("maryyyyyyyyyyy", 
		lr_unmask("626c3adbbf681f14599bfbc5394f"), 
		"18.212.178.84:80");

	web_add_cookie("userCart=%7B%22userId%22%3A-1%2C%22productsInCart%22%3A%5B%5D%7D; DOMAIN=18.212.178.84");

	web_add_cookie("_ga=GA1.1.1407658141.1651259723; DOMAIN=18.212.178.84");

	web_add_cookie("_gid=GA1.1.1769308473.1651259723; DOMAIN=18.212.178.84");

	web_url("ALL", 
		"URL=http://18.212.178.84/catalog/api/v1/DemoAppConfig/parameters/by_tool/ALL", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Access-Control-Request-Headers", 
		"content-type,soapaction");

	web_add_header("Access-Control-Request-Method", 
		"POST");

	web_add_auto_header("Origin", 
		"http://18.212.178.84");

	web_add_header("Sec-Fetch-Mode", 
		"cors");

	web_custom_request("GetAccountConfigurationRequest", 
		"URL=http://18.212.178.84:8081//accountservice/ws/GetAccountConfigurationRequest", 
		"Method=OPTIONS", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceGetAccountConfigurationRequest");

	web_custom_request("GetAccountConfigurationRequest_2", 
		"URL=http://18.212.178.84:8081//accountservice/ws/GetAccountConfigurationRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountConfigurationRequest xmlns=\"com.advantage.online.store.accountservice\"></GetAccountConfigurationRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_add_cookie("_gat=1; DOMAIN=18.212.178.84");

	web_revert_auto_header("Origin");

	web_url("categories", 
		"URL=http://18.212.178.84/catalog/api/v1/categories", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	web_websocket_close("ID=0", 
		"Code=1001", 
		LAST);

	web_url("search", 
		"URL=http://18.212.178.84/catalog/api/v1/deals/search?dealOfTheDay=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("open_site",LR_AUTO);

	lr_start_transaction("registration");

	web_url("register-page.html", 
		"URL=http://18.212.178.84/app/user/views/register-page.html", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Access-Control-Request-Headers", 
		"content-type,soapaction");

	web_add_header("Access-Control-Request-Method", 
		"POST");

	web_add_auto_header("Origin", 
		"http://18.212.178.84");

	web_add_header("Sec-Fetch-Mode", 
		"cors");

	web_custom_request("GetCountriesRequest", 
		"URL=http://18.212.178.84:8081//accountservice/ws/GetCountriesRequest", 
		"Method=OPTIONS", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceGetCountriesRequest");

	web_custom_request("GetCountriesRequest_2", 
		"URL=http://18.212.178.84:8081//accountservice/ws/GetCountriesRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetCountriesRequest xmlns=\"com.advantage.online.store.accountservice\"></GetCountriesRequest></soap:Body></soap:Envelope>", 
		LAST);

	lr_end_transaction("registration",LR_AUTO);

	lr_start_transaction("data_input");

	web_add_header("Access-Control-Request-Headers", 
		"content-type,soapaction");

	web_add_header("Access-Control-Request-Method", 
		"POST");

	web_add_header("Sec-Fetch-Mode", 
		"cors");

	lr_think_time(46);

	web_custom_request("AccountCreateRequest", 
		"URL=http://18.212.178.84:8081//accountservice/ws/AccountCreateRequest", 
		"Method=OPTIONS", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceAccountCreateRequest");

	web_custom_request("AccountCreateRequest_2", 
		"URL=http://18.212.178.84:8081//accountservice/ws/AccountCreateRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountCreateRequest xmlns=\"com.advantage.online.store.accountservice\"><accountType>USER</accountType><address>street</address><allowOffersPromotion>true</allowOffersPromotion><cityName>Nizhniy Novgorod</cityName><countryId>Russia,ru</countryId><email"
		">dfdfvff@yandex.ru</email><firstName>Mariya</firstName><lastName>Bogolyubova</lastName><loginName>maryyyyyyyyyyy</loginName><password>544554Mary</password><phoneNumber>+79524441001</phoneNumber><stateProvince>region</stateProvince><zipcode>547859</zipcode></AccountCreateRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_add_header("Access-Control-Request-Headers", 
		"content-type,soapaction");

	web_add_header("Access-Control-Request-Method", 
		"POST");

	web_add_header("Sec-Fetch-Mode", 
		"cors");

	web_custom_request("AccountLoginRequest", 
		"URL=http://18.212.178.84:8081//accountservice/ws/AccountLoginRequest", 
		"Method=OPTIONS", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceAccountLoginRequest");

	web_custom_request("AccountLoginRequest_2", 
		"URL=http://18.212.178.84:8081//accountservice/ws/AccountLoginRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLoginRequest xmlns=\"com.advantage.online.store.accountservice\"><email>dfdfvff@yandex.ru</email><loginPassword>544554Mary</loginPassword><loginUser>maryyyyyyyyyyy</loginUser></AccountLoginRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_set_sockets_option("INITIAL_AUTH", "BASIC");

	web_revert_auto_header("Origin");

	web_url("973651204", 
		"URL=http://18.212.178.84/order/api/v1/carts/973651204", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("data_input",LR_AUTO);

	lr_start_transaction("logout");

	web_add_header("Access-Control-Request-Headers", 
		"content-type,soapaction");

	web_add_header("Access-Control-Request-Method", 
		"POST");

	web_add_auto_header("Origin", 
		"http://18.212.178.84");

	web_add_header("Sec-Fetch-Mode", 
		"cors");

	lr_think_time(14);

	web_custom_request("AccountLogoutRequest", 
		"URL=http://18.212.178.84:8081//accountservice/ws/AccountLogoutRequest", 
		"Method=OPTIONS", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceAccountLogoutRequest");

	web_custom_request("AccountLogoutRequest_2", 
		"URL=http://18.212.178.84:8081//accountservice/ws/AccountLogoutRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://18.212.178.84/", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLogoutRequest xmlns=\"com.advantage.online.store.accountservice\"><loginUser>973651204</loginUser><base64Token>Basic bWFyeXl5eXl5eXl5eXk6NTQ0NTU0TWFyeQ==</base64Token></AccountLogoutRequest></soap:Body></soap:Envelope>", 
		LAST);

	lr_end_transaction("logout",LR_AUTO);

	return 0;
}