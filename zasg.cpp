#include<iostream>
using namespace std;

//--------FUNCTIONS & VARIABLES---------

int balcony();
int bedroom();
int dining();
int basement();
int wrench = 0;
int cabinet();
int lighter = 0;
int ignite();
int key = 0;
int dark();
int zombies_killed = 0;
static int visited_balcony = 0;
static int visited_bedroom = 0;
static int visited_dining = 0;

//-------------MAIN---------------

int main() {

	int roomnow = 1;

	cout << "------------------------ZASG---------------------------\n";
	cout << "\nZASG is a text based Zombie Apocalypse Survival Game!\n";
	cout << "Enter the number in the brackets to perform that action.\n";
	cout << "Press 0 to exit.\n\n";

	do{
		switch(roomnow){

			case 1:
				roomnow = balcony();
				break;
                        case 2:
                                roomnow = bedroom();
                                break;
                        case 3:
                                roomnow = dining();
                                break;
                        case 4:
                                roomnow = basement();
                                break;
			default:
				cout << "\nGAMEOVER.\nZombies Killed = " << zombies_killed << "/3" << endl;
				return 0;
		}
	}
	while(roomnow != 0);
}

//---------------ROOMS------------------

int balcony(){

        int choice;

	if(visited_balcony == 0){

        	cout << "\nI am in The Balcony.\nZombies Killed = " << zombies_killed << endl << endl;
		cout << "I see no other building and home for miles around me. I just want to get out of this place. But They, whatever those things are, wont let me.\n";
		cout << "I see a wrench lying on the floor.\n";
        	cout << "\nI can:\n";
        	cout << "Stay in The Balcony (1)\n";
        	cout << "Go to The Bedroom (2)\n";
        	cout << "Pick up the wrench (5)\n";
        	cout << "\nI will: ";

        	cin >> choice;

		if(choice == 5){
			cout << "\nI picked up the wrench. Good call. It might come handy against them.\n";
			wrench = wrench + 1;
			visited_balcony = visited_balcony + 1;
			return 1;
		}
		else{
			return choice;
		}
	}
	if(visited_balcony == 1){

                cout << "\nI am in The Balcony.\nZombies Killed = " << zombies_killed << endl << endl;
		cout << "I picked up the wrench from The Balcony so there's nothing more left to do here.\n";
                cout << "\nI can:\n";
                cout << "Stay in The Balcony (1)\n";
                cout << "Go to The Bedroom (2)\n";
                cout << "\nI will: ";

                cin >> choice;
		return choice;
	}
}

int bedroom(){

        int choice;

	if(visited_bedroom == 0){

                cout << "\nI am in The Bedroom.\nZombies Killed = " << zombies_killed << endl << endl;
		cout << "Its dimly lit and pictures of my once happy and alive family hang on the walls. No time to regret now. I feel like something is staring at me";
		cout << " from the cabinet.\n";
        	cout << "\nI can:\n";
        	cout << "Go to The Balcony (1)\n";
        	cout << "Go to The Dining Hall (3)\n";
		cout << "Open the cabinet (5)\n";
        	cout << "\nI will: ";

        	cin >> choice;

        	if(choice == 5){
			choice = cabinet();
		}		
        	else{
                	return choice;
        	}
	}
	if(visited_bedroom == 1){

                cout << "\nI am in The Bedroom.\nZombies Killed = " << zombies_killed << endl << endl;
		cout << "I have already killed it. Nothing more to do in The Bedroom.\n";
                cout << "\nI can:\n";
                cout << "Go to The Balcony (1)\n";
		cout << "Stay in the Bedroom (2)\n";
                cout << "Go to The Dining Hall (3)\n";
                cout << "\nI will: ";

                cin >> choice;
		return choice;
	}
}

int dining(){

        int choice;

	if(visited_dining == 0){

                cout << "\nI am in The Dining.\nZombies Killed = " << zombies_killed << endl << endl;
		cout << "The dishes from our last dinner lay as they were. We were doing so good for ourselves... I need to keep moving and bring justice to my wife and";
		cout << " kids. My lighter is still on the shelf.\n";
        	cout << "\nI can:\n";
	        cout << "Go to The Bedroom (2)\n";
        	cout << "Stay in The Dining (3)\n";
	        cout << "Go to The Basement (4)\n";
		cout << "Take the lighter (5)\n";
        	cout << "\nI will: ";
        	cin >> choice;

		if(choice == 5){
			cout << "\nI picked up the lighter. I ignite it to check if it still works. Great! It ignites. This might come handy.\n";
			lighter = lighter + 1;
			visited_dining = visited_dining + 1;
			return 3;
		}
        	else{
                	return choice;
        	}
	}
	if(visited_dining == 1){

                cout << "\nI am in The Dining.\nZombies Killed = " << zombies_killed << endl << endl;
		cout << "I have already taken the lighter so there's nothing more left here to do.\n";
                cout << "\nI can:\n";
                cout << "Go to The Bedroom (2)\n";
                cout << "Stay in The Dining (3)\n";
                cout << "Go to The Basement (4)\n";
                cout << "\nI will: ";

                cin >> choice;
		return choice;
	}
}

int basement(){

        int choice;

       	cout << "\nI am in The Basement.\nZombies Killed = " << zombies_killed << endl << endl;
	cout << "It is pitch black down here. There is a door to exit this house at the opposite end. I just hope i dont attract any one of those.\n";
        cout << "\nI can:\n";
        cout << "Go to The Dining (3)\n";
	cout << "Ignite the lighter (5)\n";
	cout << "Walk towards the exit door (6)\n";
        cout << "\nI will: ";
        cin >> choice;

	if(choice == 5){
		if(lighter > 0){
			choice = ignite();
		}
		else{
			cout << "\nI didn't take the lighter from The Dining.\n";
			return 4;
		}
	}
	if(choice == 6){
		choice = dark();
	}
        else{
                return choice;
        }
}

//-----------ACTIONS INSIDE ROOMS------------

int cabinet(){

	int choice;

	cout << "\nAs I move closer, I hear some light breathing coming from the cabinet. I am rethinking my decision.\n";
        cout << "\nI can:\n";
        cout << "Open the cabinet and face whatever is in there (7)\n";
        cout << "\nI will: ";
        cin >> choice;

        if(choice == 7){

		cout << "\nI decide to face whatever is in the cabinet. The breathing is getting heavier. I am standing at the base of the cabinet and just about to";
                cout << " open it when it swings open itself. I take a step back and hold the wrench over my head. It comes running at me on all fours!\n";
                cout << "\nI can:\n";
                cout << "Hit it on the head with the wrench (8)\n";
                cout << "Try to kick it (9)\n";
                cout << "\nI will: ";
                cin >> choice;

                if(choice == 8){

			if(wrench == 1){

				cout << "\nI close my eyes and swing the wrench and hit it on the head! It flies to the other side of the room and lies lifeless now.\n";
				zombies_killed = zombies_killed + 1;
				visited_bedroom = visited_bedroom + 1;
				return 2;
			}
			else{
				cout << "\nI didn't pick up the wrench from the balcony! I stand defenceless as the thing jumps on me.\n";
				cout << "\nI can:\n";
	                	cout << "Try to kick it (9)\n";
        	        	cout << "\nI will: ";
               			cin >> choice;
			}
                }
                if(choice == 9){
			cout << "\nI try to kick it in the chest but it bites my foot! Pain shoots through my whole body and I start to lose my balance";
                       	cout << " and fall down. The thing is getting ready to jump on me again!\n";

			if(wrench == 1){
				cout << "My wrench fell away from me.\n";
                       		cout << "\nI can:\n";
	               		cout << "Try to crawl towards the wrench (5)\n";
                       		cout << "Let it jump on me and accept my fate (6)\n";
                       		cout << "\nI will: ";
                       		cin >> choice;

                       		if (choice == 5){
					cout << "\nI start crawling towards the wrench but the thing jumps on my back and bites my neck! I am suddenly paralysed and cant";
                                	cout << " move. I lie motionless while it eats me alive. Unbearable pain. I lose all senses and die.\n";
				}
                       		if (choice == 6){
                                	cout << "\nI just lie there and let it jump on me. I am being eaten alive and no one can hear my screams. I just want this to be";
                                	cout << " over with quick. Unbearable pain. I lose all senses and die.\n";
				}
			}
			else{
                                cout << "\nI can:\n";
                                cout << "Let it jump on me and accept my fate (5)\n";
                                cout << "\nI will: ";
                                cin >> choice;

                                if (choice == 5){
                                        cout << "\nI just lie there and let it jump on me. I am being eaten alive and no one can hear my screams. I just want this to be";
                                        cout << " over with quick. Unbearable pain. I lose all senses and die.\n";
				}
			}
		}
	}
}

int dark(){

	int choice;

	cout << "\nI move through the dark room and hit something soft with my elbow. I spin around and get ready for the worst. A hand shoots from the dark and puts a";
	cout << " hard grip on my neck. I feel the air leaving my lungs.\n";
	cout << "\nI can\n";
	cout << "Swing the wrench towards the dark (7)\n";
	cout << "\nI will: ";
	cin >> choice;

	if(choice == 7){

		if(wrench == 1){

			cout << "\nI try to swing the wrench and manage to hit the arm. The thing growls in pain and its grip losens a little. I take advantage and pull";
			cout << " myself away from the thing. I lost its grip successfully. I hear the thing walking towards me.\n";
 			cout << "\nI can:\n";
			cout << "Run towards the exit (9)\n";
			cout << "Throw the wrench towards it (10)\n";
			cout << "\nI will: ";
			cin >> choice;

			if(choice == 9){
	
				cout << "\nI manage to get up before it reaches me and bolt towards the exit door. I miraculously made it to the door and feel a sense of";
				cout << " relief wash over me! I try to open the door but it wont budge. I curse myself for locking the door last evening.\n";
				cout << "\nI can:\n";
				cout << "Hit the door with the wrench repeatedly (6)\n";
				cout << "\nI will: ";
				cin >> choice;

				if(choice == 6){
	
					cout << "\nI hit the door with the wrench with all my strength but it results in nothing. I attracted the attenstion of more of";
					cout << " those things. I hear multiple footsteps shuffling towards me. I know whats coming. I remember the last happy moments I";
					cout << " spent with my family and sit and accept my fate. Two of those things jump on me and start eating me alive. Unbearable";
					cout << " pain. I lose all senses and die.\n";
				}
			}

			if(choice == 10){

				cout << "\nI throw the wrench towards the thing and hit it! It growned and I hear a huge thud. I guess it fell down.\n";
				cout << "\nI can:\n";
				cout << "Pick up the wrench and ignite the lighter (6)\n";
				cout << "Run towards the exit (7)\n";
				cout << "\nI will: ";
				cin >> choice;

				if(choice == 7){

	                        	cout << "\nI manage to get up before it reaches me and bolt towards the exit door. I made it to the door and feel a sense of";
	        	                cout << " relief wash over me! I try to open the door but it wont budge. I curse myself for locking the door last evening.\n";
        	        	        cout << "\nI can:\n";
                	        	cout << "Hit the door with the wrench repeatedly (8)\n";
	                	        cout << "\nI will: ";
        	                	cin >> choice;

	                	       	if(choice == 8){

	                                	cout << "\nI hit the door with the wrench with all my strength but it results in nothing. I attracted the attention of";
        		                        cout << " more of those things. I hear multiple footsteps shuffling towards me. I know whats coming. I remember the last";
        	        		        cout << " happy moments I spent with my family and sit and accept my fate. Two of those things jump on me and start eating";
                	        	        cout << " me alive. Unbearable pain. I lose all senses and die.\n";
	                        	}
				}

				if(choice == 6){
	
					if(lighter > 0){
						choice = ignite();
					}
					else{
						cout << "\nI didn't take the lighter from The Dining.\n";
						cout << "\nI can:\n";
						cout << "Run towards the exit (7)\n";
        	                		cout << "\nI will: ";
                	        		cin >> choice;
					}

					if(choice == 7){

	                                        cout << "\nI manage to get up before it reaches me and bolt towards the exit door. I made it to the door and feel a sense";
        	                                cout << " of relief wash over me! I try to open the door but it wont budge. I curse myself for locking the door last evening.\n";
                	                        cout << "\nI can:\n";
                        	                cout << "Hit the door with the wrench repeatedly (8)\n";
                                	        cout << "\nI will: ";
                                        	cin >> choice;

                                        	if(choice == 8){

                                                	cout << "\nI hit the door with the wrench with all my strength but it results in nothing. I attracted the";
	                                                cout << " attention of more of those things. I hear multiple footsteps shuffling towards me. I know whats coming.";
        	                                        cout << " I remember the last happy moments I spent with my family and sit and accept my fate. Two of those things";
                	                                cout << " jump on me and start eating me alive. Unbearable pain. I lose all senses and die.\n";
                        	                }
					}
				}
			}
		}
		if(wrench == 0){

			cout << "\nI didn't take the wrench from The Balcony.\n";
			cout << "I try to punch randomly towards the dark but fail to land any hit. The things grip gets stronger and stronger by the second. I feel";
			cout << " the life being sucked out of me. Suddenly i lose all my senses and die.\n";
		}
	}	
}

int ignite(){

	int choice;

	cout << "\nI successfully ignite the lighter. I can see better now. The basement is dusty and a complete mess. When the kids were young, we used to come down here";
	cout << " and play board games. Good memories. Just memories now. I see the key to the exit door lying on the table.\n";
	cout << "\nI can:\n";
	cout << "Take the key (7)\n";
	cout << "\nI will: ";
	cin >> choice;

	if(choice == 7){

		cout << "\nI reach for the table and pick up the key. I hear growns and footsteps outside the range of light. Two of them appear from the dark and start";
		cout << " running towards me. I hold the wrench in one hand the lighter in the other.\n";
		cout << "\nI can:\n";
		cout << "Hit one of them with the wrench (5)\n";
		cout << "Make a run for the exit door (6)\n";
		cout << "\nI will: ";
		cin >> choice;

		if(choice == 5){

			cout << "\nI decide to hit one of them with the wrench. I hit it hard on the side of its head and it flies away some distance and falls. I have no";
			cout << " time to get ready! The other one growls and jumps on me!\n";
			zombies_killed = zombies_killed + 1;
			cout << "\nI can: \n";
			cout << "Try to push it away from me (7)\n";
			cout << "Move the lighter in front of me (8)\n";
			cout << "\nI will: ";
			cin >> choice;

			if(choice == 7){

				cout << "\nIt jumps on me and I try to push it away from me. It bites my neck in the process. I am suddenly paralysed and cant move.";
				cout << " I lie motionless while it eats me alive. Unbearable pain. I lose all senses and die.\n";
			}
			if(choice == 8){

				zombies_killed = zombies_killed + 1;
				cout << "\nI move the the lighter in front of me as it jumps on me. The thing catches fire the instant it comes in contact with the";
				cout << " fire. I push it away and back off. Listening to the things screams was hell. I run towards the exit door and put the key in it.";
				cout << " It clicks! I push open the door and run up the stairs and finally into then open. Its a cold and silent night.\n";
				cout << "Killing my wife and kids wasn't easy. But those things weren't the people they once were. I walk away from the house";
				cout << " where those things- my kids and wife, lay dead, in search of another living human being.\n";
			}
		}
		if(choice == 6){

			cout << "\nI run towards the door before they could reach me and put the key in the door. It clicks! Those things are a few feet away from me.";
			cout << " I push open the door and shut it behind me quickly. I turn the key and lock the door. They punch and kick the door but fail to break";
			cout << " it. I take sigh of relief and run up the stairs and into the open. Its a cold and silent night.\n";
			cout << "I dont feel good about leaving my daughter and wife alive in there. If you can even call them alive. Those things are not the people";
			cout << " they once were. I should have killed them to end their suffering. I walk away from the house in search of another living human being.\n";
		}
	}
}
