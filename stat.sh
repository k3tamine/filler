# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    stat.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/24 17:33:49 by mgonon            #+#    #+#              #
#    Updated: 2017/10/26 13:20:47 by mgonon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

player1=mgonon.filler
player2=abanlin.filler

n_turns=5
map=02

p1=0;
p2=0;

while [ $n_turns != 0 ]
do
	./filler_vm -f ./maps/map$map -p1 \
		./players/$player1 -p2 \
		./players/$player2 > /dev/null
	result=$(cat filler.trace | grep won)
	if echo "$result" | grep -q "$player1"
	then
		((p1++))
	else
		((p2++))
	fi
	((n_turns--))
done

echo $player1
echo $p1
echo $player2
echo $p2
