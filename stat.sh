# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    stat.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/24 17:33:49 by mgonon            #+#    #+#              #
#    Updated: 2017/10/26 12:53:02 by mgonon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# mgonon 79 vs 21 abanlin
# abanlin 0 vs 100 mgonon
# carli 29 vs 71 mgonon
# mgonon 80 vs 20 carli
# champely 9 vs 91 mgonon
# mgonon 91 vs 9 champely
# grati vs mgonon
# mgonon vs grati
# hcoa vs mgonon
# mgonon vs hcao
# superjeannot vs mgonon
# mgonon vs superjeannot

player1=mgonon.filler
player2=superjeannot.filler

n_turns=40
map=00

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
