local directionHitFrom = DIR_NONE

function GetMovementDirection()
    --Do we have a head?
    if (hasHead) then
        basicSeek = true
	else
		--	Run away!
		if (directionHitFrom == DIR_UP) then
            yMove = -1
		elseif (directionHitFrom == DIR_DOWN) then
            yMove = 1
        elseif (directionHitFrom == DIR_RIGHT) then
            xMove = 1
        elseif (directionHitFrom == DIR_LEFT) then
            xMove = -1
        end
	end
end

function Hit(damage, dir, playerDamage)
	directionHitFrom = dir
	
    --Head got knocked off?
    if (hasHead) then
        --Only knock the head off the black one if two damage is done
        if (tonumber(Self.health) - damage < 2) then
            hasHead = false
                    
            --Start moving quickly, once head is off
            Self.beatsPerMove = 1
            
            --Show headless image and end the beat animation
            Self.animOverride = 8
            
            -- Run away immediately
            Self.currentMoveDelay = 0
        end
    end
end