#include <stdio.h>
#define MAX_SIZE 100

int main(){
	int luachon, n = 0, value1, value2, value3, index, index2, flag, count = 0, luachon2;
	float tb = 0,  sum = 0;
	int found_case_3 = 0;
	int a[MAX_SIZE];
	int index_search = -1;
	int min = a[0];
	int l = 0; 
	int r = n - 1;

	do{
		printf ("\n+--------------------------------MENU QUAN LI--------------------------------+\n");
		printf ("|1. Nhap so luong phan tu va gia tri cua tung phan tu cho mang               |\n");
		printf ("|2. In ra cac gia tri trong mang                                             |\n");
		printf ("|3. In ra cac so lon hon gia tri trung binh cua cac phan tu co trong mang    |\n");
		printf ("|4. In ra gia tri nho nhat cua cac phan tu co trong mang                     |\n");  
		printf ("|5. Them mot phan tu vao dau mang                                            |\n");
		printf ("|6. Xoa mot phan tu tai vi tri cu the                                        |\n");
		printf ("|7. Sap xep mang theo thu tu tang dan                                        |\n");
		printf ("|8. Kiem tra su ton tai cua phan tu trong mang                               |\n");
		printf ("|9. In ra cac phan tu xuat hien 2 lan trong mang                             |\n");
		printf ("|10. In ra so lan xuat hien cua 1 phan tu                                    |\n");
		printf ("|11. THoat chuong trinh                                                      |\n");
		printf ("+----------------------------------------------------------------------------+\n");
		
		do{
			printf ("Moi ban nhap vao lua chon: ");
			if (scanf("%d", &luachon) != 1 || luachon < 1 || luachon > 11){
				printf ("Loi nhap lieu, vui long nhap lai !!!");
				int c;
				while ((c = getchar()) != '\n' && c != EOF);
				continue;
			}
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
			break;
		} while (1);
		
		switch (luachon){
			case 1:
				printf ("---KHAI BAO MANG---\n");
				do{
				printf ("Moi ban nhap vao do dai cua mang: ");
				if (scanf("%d", &n) != 1 || n < 1){
					printf ("Loi nhap lieu, vui long nhap lai !!!");
					int c;
					while ((c = getchar()) != '\n' && c != EOF);
					continue;
				}
				int c;
				while ((c = getchar()) != '\n' && c != EOF);
				break;
			} while (1);
			
			for(int i = 0; i < n; i++){
				do{
					printf ("Moi ban nhap vao gia tri cho phan tu a[%d]: ", i);
					if (scanf("%d", &a[i]) != 1){
						printf ("Loi nhap lieu, vui long nhap lai !!!");
						int c;
						while ((c = getchar()) != '\n' && c != EOF);
						continue;
					}
					int c;
					while ((c = getchar()) != '\n' && c != EOF);
					break;
				} while (1);
			}
			printf ("\n");
			break;
			
			case 2:
				if (n == 0){
					printf ("Chua co phan tu trong mang, vui long quay lai lua chon 1 khai bao");
				} else {
					printf ("---MANG BAN DA NHAP LA---\n");
					for (int i = 0; i < n; i++){
						printf ("%5d", a[i]);
					}
				}
				printf("\n");
				break;
				
			case 3:
				for (int i = 0; i < n; i++){
					sum += a[i];
				}
				tb = sum / n;
				printf ("Gia tri trung binh cua mang la: %.2f\n", tb);
				printf ("Cac so lon hon gia tri trung binh trong mang ban da nhap la: ");

				for (int i = 0; i < n; i++){
					if (a[i] > tb){
						printf ("%5d", a[i]);
						found_case_3 = 1;
					}
				}
				if (found_case_3 == 0){
                     printf ("Khong co phan tu nao lon hon gia tri trung binh.");
                }
				printf ("\n");
				break;
				
			case 4:
				if (n == 0){
                    printf ("Mang rong, khong the tim gia tri nho nhat.\n");
                    break;
                }
				printf ("Ban da lua chon in ra so nho nhat trong mang.\n");
				for (int i = 0; i < n; i++){
					if (a[i] < min){
						min = a[i];
					}
				}
	
				printf ("So nho nhat trong mang ban da nhap la: %d\n", min);
				printf ("\n");
				break;
			
			case 5:
				printf ("Ban da lua chon them moi 1 phan tu vao dau mang.\n");
				do{
					printf ("Moi ban nhap vao gia tri muon them: ");
					if (scanf("%d", &value1) != 1){
						printf ("Loi nhap lieu, vui long nhap lai !!!");
						int c;
						while ((c = getchar()) != '\n' && c != EOF);
						continue;
					}
					int c;
					while ((c = getchar()) != '\n' && c != EOF);
					break;
				} while (1);
				
				for (int i = n; i > 0; i--){
					a[i] = a[i - 1];
				}
				a[0] = value1;
				n++;
				
				printf ("Mang cua ban sau khi them:");
				for (int i = 0; i < n; i++){
					printf ("%5d", a[i]);
				}
				
				printf("\n");
				break;
				
			case 6:
				printf ("Ban da chon chuc nang xoa phan tu.\n");
				do{
					printf ("Moi ban nhap vao vi tri muon xoa: ");
					if (scanf("%d", &index) != 1 || index < 0 || index > n){
						printf ("Loi nhap lieu, vui long nhap lai !!!");
						int c;
						while ((c = getchar()) != '\n' && c != EOF);
						continue;
					}
					int c;
					while ((c = getchar()) != '\n' && c != EOF);
					break;
				} while (1);	
			 	
			 	for (int i = index; i < n - 1; i++){
			 		a[i] = a[i + 1];
				}
				n--;
				
				printf ("Mang cua ban sau khi xoa:");
				for (int i = 0; i < n; i++){
					printf ("%5d", a[i]);
				}
				printf("\n");
				break;
				
			case 7:
				//sawp xep theo kieu selectionSort
				if (n == 0){
                    printf ("Mang rong, khong the sap xep.\n");
                    break;
                }
				printf ("Ban da chon chuc nang sap xep selectionSort.\n");
				for (int i = 0; i < n - 1; i++){
					int index2 = i;
					for (int j = i + 1; j < n; j++){
						if (a[j] < a[index2]){
							index2 = j;
						}
					}
					int temp = a[i];
					a[i] = a[ index2];
					a[index2] = temp;
				}
				printf ("Mang cua ban sau khi su dung selectionSort sap xep tang dan:");
				for (int i = 0; i < n; i++){
					printf ("%5d", a[i]);
				}
				printf ("\n");
				break;
				
			case 8:
				if (n == 0){
                    printf ("Mang rong, khong the tim kiem.\n");
                    break;
                }
                
                printf ("Ban da chon chuc nang tim kiem binarySearch.\n");
                 for (int i = 0; i < n - 1; i++){
                    int min_idx = i;
                    for (int j = i + 1; j < n; j++){
                        if (a[j] < a[min_idx]){
                            min_idx = j;
                        }
                    }
                    int temp = a[i];
                    a[i] = a[min_idx];
                    a[min_idx] = temp;
                }
                
                printf ("Mang sap xep truoc khi tim kiem:");
                for (int i = 0; i < n; i++){
                    printf ("%5d", a[i]);
                }
                printf ("\n");

                do{
                    printf ("Moi ban nhap vao gia tri muon tim kiem: ");
                    if (scanf("%d", &value2) != 1){
                        printf ("Loi nhap lieu, vui long nhap lai !!!\n");
                        int c;
                        while ((c = getchar()) != '\n' && c != EOF);
                        continue;
                    }
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF);
                    break;
                } while (1);
                
                index_search = -1;
                while (l <= r){
                    int mid = l + (r - l) / 2;
                    if (a[mid] == value2){
                        index_search = mid;
                        break; 
                    } else if (a[mid] < value2){
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                    
                if (index_search != -1){
                    printf ("Tim thay gia tri %d tai vi tri a[%d].\n", value2, index_search);
                } else {
                    printf ("Khong tim thay vi tri cua gia tri %d trong mang.\n", value2);
                }
                break;
				
			case 9:
				printf ("Case 9 bo");
				break;
				
			case 10:
				if (n == 0){
                    printf ("Mang rong, khong the dem.\n");
                    break;
                }
                
                do{
                    printf ("Moi ban nhap vao gia tri muon dem: ");
                    if (scanf("%d", &value3) != 1){
                        printf ("Loi nhap lieu, vui long nhap lai !!!\n");
                        int c;
                        while ((c = getchar()) != '\n' && c != EOF);
                        continue;
                    }
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF);
                    break;
                } while (1);
                
				for (int i = 0; i < n; i++){
                    if (a[i] == value3){
                        count++;
                    }
                }
                printf("So lan xuat hien cua gia tri %d trong mang la: %d\n", value3, count);
                printf ("\n");
                break;
				
			case 11:
				printf ("Xac nhan thoat chuong trinh (1 - Co || 0 - Khong) ?\n");
				do{
					printf ("Moi ban nhap vao (1 - Co || 0 - Khong): ");
					if (scanf("%d", &luachon2) != 1 || luachon2 < 0 || luachon2 > 1){
						printf ("Loi nhap lieu, vui long nhap 1 hoac 0 !!!");
						int c;
						while ((c = getchar()) != '\n' && c != EOF);
						continue;
					}
					int c;
					while ((c = getchar()) != '\n' && c != EOF);
					break;
				} while (1);
				 
				if (luachon2 == 1){
					printf ("Ket thuc chuong trinh !!!");
					return 0;
				} else {
					printf ("Da huy thao tac !");
				}
				break;
			
			default:
				break;
		} // cua switch
	} while (1); // cua do menu
	return 0;
} // cua main


